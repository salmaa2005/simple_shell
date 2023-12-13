#include "shell.h"

/**
 * read_line - Reads a line from standard input.
 * Return: returns a pointer to the read line
 */
char *read_line(void)

{
	char *line = NULL;
	size_t len = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))		   /* for non-interactive handling */
		write(STDOUT_FILENO, "$ ", 2); /* Write 2 charcters ($<space>)*/
	n = getline(&line, &len, stdin);

	if (n == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
