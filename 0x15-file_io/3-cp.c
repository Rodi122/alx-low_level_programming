#include "main.h"
/**
 * error_file - function to check if file can be opened
 * @file_from: file from
 * @file_to: file to
 * @argv: argument vector
 * Return: None
 */
void error_file(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - checks the code
 * @argc: number of args
 * @argv: argument v
 * Return: zero
 */
int main(int argc, char *argv[])
{
	int from, to, Eclose;
	ssize_t n, wr;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	from = open(argv[1], O_RDONLY);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(from, to, argv);

	n = 1024;
	while (n == 1024)
	{
		n = read(from, buf, 1024);
		if (n == -1)
			error_file(-1, 0, argv);
		wr = write(to, buf, n);
		if (wr == -1)
			error_file(0, -1, argv);
	}

	Eclose = close(from);
	if (Eclose == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from);
		exit(100);
	}

	Eclose = close(to);
	if (Eclose == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from);
		exit(100);
	}
	return (0);
}
