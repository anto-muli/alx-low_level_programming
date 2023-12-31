#ifndef IO_
#define IO_
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int _putchar(char c);
int _strlen(const char *s);
int append_text_to_file(const char *filename, char *text_content);
#endif
