#include "main.h"
#define BUF_SIZE 64
void print_elf_header(uint8_t *buffer);
int main(int argc, char *argv[]);

/**
 * print_error_and_exit - Function prints error message to stderr and exit.
 * @exit_code: The exit code
 * @error_message: The error message to display
 */
void print_error_and_exit(int exit_code, const char *error_message)
{
	dprintf(STDERR_FILENO, "%s\n", error_message);
	exit(exit_code);
}

/**
 * print_hex - Function prints the hex values of a buffer.
 * @buffer: The buffer to print
 * @size: The size of the buffer
 */
void print_hex(uint8_t *buffer, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
		printf("%02x ", buffer[i]);
	printf("\n");
}

/**
 * print_elf_header - Function prints the ELF header information.
 * @buffer: Buffer containing the ELF header.
 */
void print_elf_header(uint8_t *buffer)
{
	printf("ELF Header:\n");
	printf("  Magic:   ");
	print_hex(buffer, 16);
	printf("  Class: ELF%d\n", buffer[4] == 1 ? 32 : 64);
	printf("  Data:  %s\n", buffer[5] == 1 ?
		"2's complement, little endian" : "2's complement, big endian");
	printf("  Version: %d (current)\n", buffer[6]);
	printf("  OS/ABI:  UNIX - %s\n", buffer[7] == 0 ? "System V" : "Other");
	printf("  ABI Version: %d\n", buffer[8]);
	printf("  Type: ");
	print_hex(&buffer[16], 2);
	printf("  Entry point address: ");
	print_hex(&buffer[24], 4);
}

/**
 * main - Entry point of the program
 * @argc: Argument count
 * @argv: Argument vector.
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	int fd;
	ssize_t bytes_read;
	uint8_t buffer[BUF_SIZE];

	if (argc != 2)
		print_error_and_exit(98, "Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error_and_exit(98, "Error: Can't open file");

	bytes_read = read(fd, buffer, BUF_SIZE);
	if (bytes_read == -1)
		print_error_and_exit(98, "Error: Can't read from file");

	if (bytes_read < BUF_SIZE)
		print_error_and_exit(98, "Error: Invalid ELF file");

	print_elf_header(buffer);

	if (close(fd) == -1)
		print_error_and_exit(100, "Error: Can't close file descriptor");

	return (0);
}
