#include "main.h"
/**
 * append_text_to_file - adds text ot the EOF
 * @filename: name of file to be appeded
 * @text_content: the text to append
 * Return: 1 or -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd = 0;
	int charlen = 0;
	int i = 0;

	if (!filename)
	{
		return (-1);
	}
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd < 0)
	{
		return (-1);
	}
	if (text_content)
	{
		while (text_content[i])
		{
			i++;
		}
		charlen = write(fd, text_content, i);
		if (charlen < 0)
		{
			return (-1);
		}
	}
	close(fd);
	return (1);
}
