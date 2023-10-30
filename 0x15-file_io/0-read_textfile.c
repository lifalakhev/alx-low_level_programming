#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Function that reads text file prints to STDOUT
 * @filename: Text file being read
 * @letters: No. of letters to be read
 * Return: w actual No. of bytes read & printed
 *        0 when function fails or filename is NULL.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);
	free(buf);
	close(fd);
	return (w);
}
