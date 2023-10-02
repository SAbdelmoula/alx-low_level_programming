#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- read the text file printed to STDOUT
 * @filename: read the text file
 * @letters: the letter numbers to be read
 * Return: w- actual number of bytes read and printed
 *        0 when the function fails or filename is NULL
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buff;
	ssize_t fd;
	ssize_t z;
	ssize_t e;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buff = malloc(sizeof(char) * letters);
	e = read(fd, buff, letters);
	z = write(STDOUT_FILENO, buff, e);

	free(buff);
	close(fd);
	return (z);
}
