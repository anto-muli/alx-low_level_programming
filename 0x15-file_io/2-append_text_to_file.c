#include "main.h"

/**
 * append_text_to_file - Appends text to file's  end
 * @filename: A pointer to the file name
 * @text_content: The string to add to the file's end
 *
 * Return: If the function fails or fn is NULL - -1.
 * If the file does not exist the user lacks write perm -1.
 * Otherwise - 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int a, x, anto = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (anto = 0; text_content[anto];)
			anto++;
	}
	a = open(filename, O_WRONLY | O_APPEND);
	x = write(a, text_content, anto);

	if (a == -1 || x == -1)
		return (-1);

	close(a);

	return (1);
}
