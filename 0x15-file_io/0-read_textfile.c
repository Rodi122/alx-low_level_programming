#include "main.h"
/**
 * read_textfile - Reads a textfile and prints it
 * @filename: the file
 * @letters: the number of chars to print
 * Return: the number of chars that could be printed
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fd = 0;
	ssize_t charlen = 0;
	char *text;

	if (!filename || !letters)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);

	text = malloc(sizeof(char) * (letters));
	if (!text)
		return (0);

	charlen = read(fd, text, letters);
	charlen = write(STDOUT_FILENO, text, charlen);
	if (charlen < 0)
		return (0);

	close(fd);
	free(text);
	return (charlen);
}
