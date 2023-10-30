#include "main.h"

/**
 * append_text_to_file - Function that appends text at end of file
 * @filename: name of file
 * @text_content: String to add at end of file
 *
 * Return: int
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, bytes_write;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
	{
		if (filename)
			return (1);
		else
			return (-1);
	}

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
		return (-1);

	bytes_write = write(fd, text_content, strlen(text_content));

	if (bytes_write == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);

	return (1);
}
