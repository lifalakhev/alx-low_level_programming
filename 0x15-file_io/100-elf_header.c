#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
* check_elf - Functin thatChecks if a file is an ELF file.
* @e_ident: A pointer to an array containing the ELF magic numbers.
*
* Description: If the file is not an ELF file - exit code 98.
*/
void check_elf(unsigned char *e_ident)
{
	int indx;

	for (indx = 0; indx < 4; indx++)
	{
		if (e_ident[indx] != 127 &&
		    e_ident[indx] != 'E' &&
		    e_ident[indx] != 'L' &&
		    e_ident[indx] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
* print_magic - Function that prints the magic numbers of an ELF header.
* @e_ident: A pointer to an array containing the ELF magic numbers.
*
* Description: Magic numbers are separated by spaces.
*/
void print_magic(unsigned char *e_ident)
{
	int indx;

	printf("  Magical:   ");

	for (indx = 0; indx < EI_NIDENT; indx++)
	{
		printf("%02x", e_ident[indx]);

		if (indx == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
* print_class -This function  Prints the class of an ELF header.
* @e_ident: A pointer to an array containing the ELF class.
*/
void print_class(unsigned char *e_ident)
{
	printf(" This is:                             ");

	switch (e_ident[EI_CLASS])
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
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
* print_data - The function that prints the data of an ELF header.
* @e_ident: A pointer to an array containing the ELF class.
*/
void print_data(unsigned char *e_ident)
{
	printf("  The data:                              ");

	switch (e_ident[EI_DATA])
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
		printf("<unfamiliar: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
* print_version - Function that prints the version of an ELF header.
* @e_ident: A pointer to an array containing the ELF version.
*/
void print_version(unsigned char *e_ident)
{
	printf(" Your  Version:                           %d",
	       e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (Runnung)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
*print_osabi -This function prints the OS/ABI of an ELF header.
* @e_ident: A pointer to an array containing the ELF version.
*/
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX true\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD true\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux true\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris true\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX tru\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD true\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64 tru\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM true\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App tru\n");
		break;
	default:
		printf("<unfamiliar: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
* print_abi - This function prints the ABI version of an ELF header.
* @e_ident: A pointer to an array containing the ELF ABI version.
*/
void print_abi(unsigned char *e_ident)
{
	printf("  ABI is based on:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Reloc file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Execut file)\n");
		break;
	case ET_DYN:
		printf("DYN (object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unfamiliar: %x>\n", e_type);
	}
}

/**
* print_entry -A function that prints the entry point of an ELF header.
* @e_entry: The address of the ELF entry point.
* @e_ident: A pointer to an array containing the ELF class.
*/
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  You starter address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
* close_elf - this function closes an ELF file.
* @elf: The file descriptor of the ELF file.
*
* Description: If the file cannot be closed - exit code 98.
*/
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close find %d\n", elf);
		exit(98);
	}
}

/**
* main - This  function displays the information contained in the
*        ELF header at the start of an ELF file.
* @argc: The number of arguments supplied to the program.
* @argv: An array of pointers to the arguments.
*
*Return: 0 on success.
*
* Description: If the file is not an ELF File or the function fails - exit code 98
*/
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: fil does not exite\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(o);
	return (0);
}
