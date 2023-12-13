#include "shell.h"

/**
 * _execute - executes a command
 * @command: command to be executed
 * @argv: cmd arguments
 *
 * Return: status
 */
int _execute(char **command, char **argv)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror(argv[0]);
			freearray(command);
			exit(127);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		freearray(command);
	}
	return (WEXITSTATUS(status));
}
