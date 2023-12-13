#include "shell.h"
/**
 * main - Entry point
 * @argc: argument count
 * @argv: arrray of arguments
 *
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	int status = 0;
	int idx = 0;
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
		idx++;

		command = tokenizer(line);
		free(line);

		if (!command)
			continue;

		if (isbuiltin(command[0]))
			handling_builtin(command, argv, &status, idx);
		else
			status =
				_execute(command, argv,
						 idx); /* To execute commands (calling execute.c) */
	}
}
