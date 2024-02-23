#include "main.h"
/**
 * create_file - creates the file and ads permissions
 * @filename: name of the file
 * @text_content: is a NULL terminated string to write to the file
 * Return: 1 or -1
 */
int create_file(const char *filename, char *text_content)
{
	ssize_t fd = 0;
	ssize_t charlen = 0;
	ssize_t i = 0;

	if (!filename)
	{
		return (-1);
	}
	if (!text_content)
	{
		text_content = "";
	}
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 00600);
	if (fd < 0)
	{
		return (-1);
	}
	while (text_content[i])
	{
		i++;
	}
	charlen = write(fd, text_content, i);
	if (charlen < 0)
	{
		return (-1);
	}
	close(fd);
	return (1);
}
