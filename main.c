#include "shell.h"

/**
 * main - Entry point of the shell
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	int status = 0;
	char **command = NULL;
	(void)argc;

	while (1)
	{

		line = read_line();
		if (line == NULL) /* EOF or CTRL D */
		{
			if (isatty(STDIN_FILENO)) /* for non-interactive handling */
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}

		/* printf("%s", line);*/

		command = tokenizer(line, " \t\n");
		free(line);

		if (!command)
			continue;

		status = _execute(command,
						  argv); /* To execute commands (calling execute.c) */
	}
}
