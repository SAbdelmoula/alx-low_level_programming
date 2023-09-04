#include "main.h"

/**
 * create_file - A function that creates a file
 * @filename: is the name of the file to create
 * @text_content: is a NULL terminated string to write to the file
 * Return: 1 on success, -1 on failure
 *         if the file already exists, truncate it
 *         if filename is NULL return -1
 *         if text_content is NULL create an empty file
 */
int create_file(const char *filename, char *text_content)
{
	int fd, a, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	a = write(fd, text_content, len);

	if (fd == -1 || a == -1)
		return (-1);

	close(fd);

	return (1);
}
