#include "main.h"
#include <elf.h>

void print_osabi(Elf64_Ehdr h);

/**
 * print_magic - print_magic number of an elf header
 * @h: the ELF structure
 * Description: the magic numbers are separated by spaces
 */
void print_magic(Elf64_Ehdr h)
{
	int e;

	printf("  Magic:   ");

	for (e = 0; e < EI_NIDENT; e++)
		printf("%2.2x%s", h.e_ident[e], e == EI_NIDENT - 1 ? "\n" : " ");
}

/**
 * print_class - prints_class of an elf header
 * @h: elf header of the structure
 */
void print_class(Elf64_Ehdr h)
{
	printf(" Class: ");

	switch (h.e_ident[EI_CLASS])
	{
		case ELFCLASS64:
			printf("ELF64");
			break;
		case ELFCLASS32:
			printf("ELF32");
			break;
		case ELFCLASSNONE:
			printf("none");
			break;
	}
	printf("\n");
}

/**
 * print_data - print_data of an elf header
 * @h: elf header of the structure
 */
void print_data(Elf64_Ehdr h)
{
	printf(" Data: ");

	switch (h.e_ident[EI_DATA])
	{
		case ELFDATA2MSB:
			printf("2's complement, big endian");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian");
			break;
		case ELFDATANONE:
			printf("none");
			break;
	}
	printf("\n");
}

/**
 * print_version - print_version of an elf header
 * @h: elf header of the structure
 */
void print_version(Elf64_Ehdr h)
{
	printf(" Version:    %d", h.e_ident[EI_VERSION]);
	switch (h.e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)");
			break;
		case EV_NONE:
			printf("%s", "");
			break;
			break;
	}
	printf("\n");
}

/**
 * print_osabi - print_osabi of an elf header
 * @h: elf header of the structure
 */
void print_osabi(Elf64_Ehdr h)
{
	printf(" OS/ABI: ");

	switch (h.e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64");
			break;
		default:
			print_osabi(h);
			break;
	}
	printf("\n");
}

/**
 * print_abi - print_abi version of an elf header
 * @h: elf header of the structure
 */
void print_abi(Elf64_Ehdr h)
{
	printf(" ABI Version: %d\n",
			h.e_ident[EI_ABIVERSION]);
}

/**
 * print_type - print_type of an elf header
 * @h: elf header of the structure
 */
void print_type(Elf64_Ehdr h)
{
	char *a = (char *)&h.e_type;
	int z = 0;

	printf(" Type: ");
	if (h.e_ident[EI_DATA] == ELFDATA2MSB)
		z = 1;
	switch (a[z])
	{
		case ET_NONE:
			printf("NONE (None)");
			break;
		case ET_REL:
			printf("REL (Relocatable file)");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)");
			break;
		case ET_CORE:
			printf("CORE (Core file)");
			break;
		default:
			printf("<unknown>: %x", a[z]);
			break;
	}
	printf("\n");
}

/**
 * print_entry - print_entry point of an elf header
 * @h: elf header of the structure
 */
void print_entry(Elf64_Ehdr h)
{
	int z = 0, l = 0;
	unsigned char *a = (unsigned char *)&h.e_entry;

	printf(" Entry point address:     0x");
	if (h.e_ident[EI_DATA] !=  ELFDATA2MSB)

	{
		z = h.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!a[z])
			z--;
		printf("%x", a[z--]);
		for (; z >= 0; z--)
			printf("%02x", a[z]);
		printf("\n");
	}
	else
	{
		z = 0;
		l = h.e_ident[EI_CLASS] == ELFCLASS64 ? 7 : 3;
		while (!a[z])
			z++;
		printf("%x", a[z++]);
		for (; z <= l; z++)
			printf("%02x", a[z]);
		printf("\n");
	}
}

/**
 * main - display the contained information in the
 *        elf header at the start of an elf file
 * @ac: the number of arguments supplied to the program
 * @av: an array of pointers to the arguments
 * Return: 1 on success 0 on failure
 */
int main(int ac, char **av)
{
	int fd;
	Elf64_Ehdr h;
	int e;

	if (ac != 2)
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n"), exit(98);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		dprintf(STDERR_FILENO, "Can't open file: \n"), exit(98);
	e = read(fd, &h, sizeof(h));
	if (e < 1 || e != sizeof(h))
		dprintf(STDERR_FILENO, "Can't read from file: \n"), exit(98);
	if (h.e_ident[0] == 0x7f && h.e_ident[1] == 'E'
			&& h.e_ident[2] == 'L' && h.e_ident[3] == 'F')
	{
		printf("ELF header:\n");
	}
	else
		dprintf(STDERR_FILENO, "Not ELF file: \n"), exit(98);

	print_magic(h);
	print_class(h);
	print_data(h);
	print_version(h);
	print_osabi(h);
	print_abi(h);
	print_type(h);
	print_entry(h);
	if (close(fd))
		dprintf(STDERR_FILENO, "Error closing file descriptor: %d\n", fd), exit(98);
	return (EXIT_SUCCESS);
}
