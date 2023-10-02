#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _strncmp - compare two strings
 * @a1: 1st string
 * @a2: 2nd string
 * @x: the max # of bytes compared
 *
 * Return: 0 if the first x bytes of a1 and a2 are equal, otherwise non 0
 */
int _strncmp(const char *a1, const char *a2, size_t x)
{
	for ( ; x && *a1 && *a2; --x, ++a1, ++a2)
	{
		if (*a1 != *a2)
			return (*a1 - *a2);
	}
	if (x)
	{
		if (*a1)
			return (1);
		if (*a2)
			return (-1);
	}
	return (0);
}

/**
 * _close - close a file descriptor and print an error message upon failure
 * @filedescriptor: the file descriptor to close
 */
void _close(int filedescriptor)
{
	if (close(filedescriptor) != -1)
		return;
	write(STDERR_FILENO, "Error: Can't close fd\n", 22);
	exit(98);
}

/**
 * _read - read from a file and print an error message upon failure
 * @filedescriptor: the file descriptor to read from
 * @buffer: the buffer to write to
 * @count: the number of bytes to read
 */
void _read(int filedescriptor, char *buffer, size_t count)
{
	if (read(filedescriptor, buffer, count) != -1)
		return;
	write(STDERR_FILENO, "Error: Can't be read from the file\n", 28);
	_close(filedescriptor);
	exit(98);
}

/**
   * elf_magic - print ELF magic no.
    * @buffer: ELF's header
     */
void elf_magic(const unsigned char *buffer)
{
	unsigned int x;

	if (_strncmp((const char *) buffer, ELFMAG, 4))
	{
		write(STDERR_FILENO, "Error: Not an ELF file\n", 23);
		exit(98);
	}
	printf("ELF Header:\n  Magic:   ");
	for (x = 0; x < 16; ++x)
		printf("%02x%c", buffer[x], x < 15 ? ' ' : '\n');
}

/**
 * elf_class - print ELF class
 * @buff: the ELF header
 *
 * Return: the bit mode (32 or 64)
 */
size_t elf_class(const unsigned char *buff)
{
	printf("  %-34s ", "Class:");

	if (buff[EI_CLASS] == ELFCLASS64)
	{
		printf("ELF64\n");
		return (64);
	}
	if (buff[EI_CLASS] == ELFCLASS32)
	{
		printf("ELF32\n");
		return (32);
	}
	printf("<unknown: %x>\n", buff[EI_CLASS]);
	return (32);
}

/**
 * elf_data - prints all ELF data
 * @buff: ELF header
 *
 * Return: 1 if big endian and 0 if not
 */
int elf_data(const unsigned char *buff)
{
	printf("  %-34s ", "Data:");

	if (buff[EI_DATA] == ELFDATA2MSB)
	{
		printf("2's complement, big endian\n");
		return (1);
	}
	if (buff[EI_DATA] == ELFDATA2LSB)
	{
		printf("2's complement, little endian\n");
		return (0);
	}
	printf("Invalid encoding of data\n");
	return (0);
}

/**
 * elf_version - print ELF version
 * @buff: the ELF header
 */
void elf_version(const unsigned char *buff)
{
	printf("  %-34s %u", "Version:", buff[EI_VERSION]);

	if (buff[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * elf_osabi - print ELF OS/ABI
 * @buff: the ELF header
 */
void elf_osabi(const unsigned char *buff)
{
	const char *os_table[19] = {
		"UNIX - System V",
		"UNIX - HP-UX",
		"UNIX - NetBSD",
		"UNIX - GNU",
		"<unknown: 4>",
		"<unknown: 5>",
		"UNIX - Solaris",
		"UNIX - AIX",
		"UNIX - IRIX",
		"UNIX - FreeBSD",
		"UNIX - Tru64",
		"Novell - Modesto",
		"UNIX - OpenBSD",
		"VMS - OpenVMS",
		"HP - Non-Stop Kernel",
		"AROS",
		"FenixOS",
		"Nuxi CloudABI",
		"Stratus Technologies OpenVOS"
	};
	printf("  %-34s ", "OS/ABI:");

	if (buff[EI_OSABI] < 19)
		printf("%s\n", os_table[(unsigned int) buff[EI_OSABI]]);
	else
		printf("<unknown: %x>\n", buff[EI_OSABI]);
}

/**
 * elf_abivers - prints the ELF ABI version
 * @buff: ELF header
 */
void elf_abivers(const unsigned char *buff)
{
	printf("  %-34s %u\n", "ABI Version:", buff[EI_ABIVERSION]);
}

/**
 * elf_type - prints the ELF type
 * @buff: ELF header
 * @big_endian: endianness (big endian if non-zero)
 */
void elf_type(const unsigned char *buff, int big_endian)
{
	char *type_table[5] = {
		"NONE (No file type)",
		"REL (Relocatable file)",
		"EXEC (Executable file)",
		"DYN (Shared object file)",
		"CORE (Core file)"
	};
	unsigned int type;

	printf("  %-34s ", "Type:");
	if (big_endian)
		type = 0x100 * buff[16] + buff[17];
	else
		type = 0x100 * buff[17] + buff[16];

	if (type < 5)
		printf("%s\n", type_table[type]);
	else if (type >= ET_LOOS && type <= ET_HIOS)
		printf("OS Specific: (%4x)\n", type);
	else if (type >= ET_LOPROC && type <= ET_HIPROC)
		printf("Processor Specific: (%4x)\n", type);
	else
		printf("<unknown: %x>\n", type);
}

/**
 * elf_entry - print entry point address
 * @buff: string containing the entry point address
 * @bit_mode: bit mode (32 or 64)
 * @big_endian: endianness (big endian if non-zero)
 */
void elf_entry(const unsigned char *buff, size_t bit_mode, int big_endian)
{
	int address_size = bit_mode / 8;

	printf("  %-34s 0x", "Entry point address:");
	if (big_endian)
	{
		while (address_size && !*(buff))
			--address_size, ++buff;
		printf("%x", *buff & 0xff);
		while (--address_size > 0)
			printf("%02x", *(++buff) & 0xff);
	}
	else
	{
		buff += address_size;
		while (address_size && !*(--buff))
			--address_size;
		printf("%x", *buff & 0xff);
		while (--address_size > 0)
			printf("%02x", *(--buff) & 0xff);
	}
	printf("\n");
}

/**
 * main - copies a file's contents to another file
 * @argc: the args count
 * @argv: the args values
 *
 * Return: Always 0
 */
int main(int argc, const char *argv[])
{
	unsigned char buff[18];
	unsigned int bit_mode;
	int big_endian;
	int filedescriptor;

	if (argc != 2)
	{
		write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
		exit(98);
	}
	filedescriptor = open(argv[1], O_RDONLY);
	if (filedescriptor == -1)
	{
		write(STDERR_FILENO, "Error: Can't read from file\n", 28);
		exit(98);
	}
	_read(filedescriptor, (char *) buff, 18);
	elf_magic(buff);
	bit_mode = elf_class(buff);
	big_endian = elf_data(buff);
	elf_version(buff);
	elf_osabi(buff);
	elf_abivers(buff);
	elf_type(buff, big_endian);

	lseek(filedescriptor, 24, SEEK_SET);
	_read(filedescriptor, (char *) buff, bit_mode / 8);
	elf_entry(buff, bit_mode, big_endian);
	_close(filedescriptor);
	return (0);
}
