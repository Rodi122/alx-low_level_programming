/*
 * File: 100-elf_header.c
 * Auth: Brennan D Baraban
 */


#include <elf.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void check_elf(unsigned char *dent);
void magic(unsigned char *dent);
void close_elf(int elff);
void data(unsigned char *dent);
void version(unsigned char *dent);
void abi(unsigned char *dent);
void osabi(unsigned char *dent);
void type(unsigned int type, unsigned char *dent);
void class(unsigned char *dent);
void entry(unsigned long int entry, unsigned char *dent);

/**
 * check_elf - ELF file checker
 * @dent: pointer to  array containing the ELF
 */
void check_elf(unsigned char *dent)
{
	int num;

	for (num = 0; num < 4; num++)
	{
		if (dent[num] != 127 &&
		    dent[num] != 'L' &&
		    dent[num] != 'F' &&
		    dent[num] != 'E')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * magic - Print magic number
 * @dent: pointer to array containing the ELF magic number
 */
void magic(unsigned char *dent)
{
	int num;

	printf("  Magic:   ");

	for (num = 0; num < EI_NIDENT; num++)
	{
		printf("%02x", dent[num]);

		if (num == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * class - Printt the ELF header
 * @dent: pointer to array containing the ELF class.
 */
void class(unsigned char *dent)
{
	printf("  Class:                             ");

	switch (dent[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", dent[EI_CLASS]);
	}
}

/**
 * data - Print the data
 * @dent: A pointer to an array
 */
void data(unsigned char *dent)
{
	printf("  Data:                              ");

	switch (dent[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", dent[EI_CLASS]);
	}
}

/**
 * version - version of an ELF header.
 * @dent: A pointer to an array
 */
void version(unsigned char *dent)
{
	printf("  Version:                           %d",
	       dent[EI_VERSION]);

	switch (dent[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * osabi - OS/ABI of an ELF header
 * @e_ident: pointer to an array
 */
void osabi(unsigned char *dent)
{
	printf("  OS/ABI:                            ");

	switch (dent[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", dent[EI_OSABI]);
	}
}

/**
 * abi - Prints the ABI version
 * @dent: A pointer to an array
 */
void abi(unsigned char *dent)
{
	printf("  ABI Version:                       %d\n",
	       dent[EI_ABIVERSION]);
}

/**
 * type - type of an ELF header
 * @type: The type
 * @dent: A pointer to an array
 */
void type(unsigned int type, unsigned char *dent)
{
	if (dent[EI_DATA] == ELFDATA2MSB)
		type >>= 8;

	printf("  Type:                              ");

	switch (type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", type);
	}
}

/**
 * print - entry point of an ELF header.
 * @entry: address of the ELF
 * @dent: A pointer to an array
 */
void entry(unsigned long int entry, unsigned char *dent)
{
	printf("  Entry point address:               ");

	if (dent[EI_DATA] == ELFDATA2MSB)
	{
		entry = ((entry << 8) & 0xFF00FF00) |
			  ((entry >> 8) & 0xFF00FF);
		entry = (entry << 16) | (entry >> 16);
	}

	if (dent[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)entry);

	else
		printf("%#lx\n", entry);
}

/**
 * close_elf - Closes the file
 * @elff: The file descriptor
 */
void close_elf(int elff)
{
	if (close(elff) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elff);
		exit(98);
	}
}

/**
 * main - prints information contained in the
 *        ELF header
 * @argc: The number of arguments
 * @argv: An array of pointers
 * Return: 0 on success.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int ore, r;

	ore = open(argv[1], O_RDONLY);
	if (ore == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(ore);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(ore, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(ore);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	magic(header->e_ident);
	class(header->e_ident);
	data(header->e_ident);
	version(header->e_ident);
	osabi(header->e_ident);
	abi(header->e_ident);
	type(header->e_type, header->e_ident);
	entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(ore);
	return (0);
}
