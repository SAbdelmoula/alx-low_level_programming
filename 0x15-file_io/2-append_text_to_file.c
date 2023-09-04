#include "main.h"

/**
 * append_text_to_file - A function that appends text at the end of a file
 * @filename:  is the name of the file
 * @text_content: the NULL terminated string to add at the end of the file
 * Return: 1 on success and -1 on failure
 *         If filename is NULL return -1
 *         If text_content is NULL,we don't add anything to the file,
 *         Return 1 if the file exists and -1 if the file does not exist
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int a, z, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	a = open(filename, O_WRONLY | O_APPEND);
	z = write(a, text_content, len);

	if (a == -1 || z == -1)
		return (-1);

	close(a);

	return (1);
}
