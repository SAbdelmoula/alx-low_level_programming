#include "main.h"

/**
 * append_text_to_file - append_text at the end of the file
 * @filename: pointer to the name of the file
 * @text_content: the string to add to the end of file
 * Return: if the function fails or filename is NULL - -1
 *         if the file does not exist the user lacks write permissions - -1
 *         Otherwise - 1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int e, z, l = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (l = 0; text_content[l];)
			l++;
	}

	e = open(filename, O_WRONLY | O_APPEND);
	z = write(e, text_content, l);

	if (e == -1 || z == -1)
		return (-1);

	close(e);

	return (1);
}
