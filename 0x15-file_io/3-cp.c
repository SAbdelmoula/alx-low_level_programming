#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - allocate 1024 bytes for the buff
 * @file: The name of the buff file is storing chars for
 * Return: pointer to the newly-allocated buff
 */
char *create_buffer(char *file)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buff);
}

/**
 * close_file - closes_file descriptors
 * @fd: the file descriptor to be closed
 */
void close_file(int fd)
{
	int t;

	t = close(fd);

	if (t == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copie the contents of the file to another one
 * @argc: the number of the arguments supplied to the program
 * @argv: an array of pointers to the arguments
 * Return: 0 on success
 * Description: if the argument count is incorrect = exit code 97
 *     if file_from doesn't exist or can't be read = exit code 98
 *     if file_to can't be created or written to = exit code 99
 *     if file_to or file_from can't be closed = exit code 100
 */
int main(int argc, char *argv[])
{
	int from, m, a, z;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	a = read(from, buff, 1024);
	m = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || a == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		z = write(m, buff, a);
		if (m == -1 || z == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		a = read(from, buff, 1024);
		m = open(argv[2], O_WRONLY | O_APPEND);

	} while (a > 0);

	free(buff);
	close_file(from);
	close_file(m);

	return (0);
}
