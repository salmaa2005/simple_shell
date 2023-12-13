#include "shell.h"
/**
 * isbuiltin - checks if a command is a builtin
 * @command: command to check
 *
 * Return: 1 if true, 0 if false
 */
int isbuiltin(char *command)
{
	char *builts[] = {"exit", "env", NULL};
	int counter;

	for (counter = 0; builts[counter]; counter++)
	{
		if (_strcmp(command, builts[counter]) == 0)
			return (1);
	}
	return (0);
}
/**
 * handling_builtin - handles builtin commands
 * @command: command to execute
 * @argv: array of arguments
 * @status: status of the shell
 * @idx: index of the command
 *
 * Return: void
 */
void handling_builtin(char **command, char **argv, int *status, int idx)
{
	(void)argv;
	(void)idx;

	if (_strcmp(command[0], "exit") == 0)
	{
		if (command[1] != NULL)
		{
			*status = atoi(command[1]);
			exiting_shell(command, status);
		}
		else
		{
			*status = 0;
			exiting_shell(command, status);
		}
	}
	else if (_strcmp(command[0], "env") == 0)
	{
		printenv(command, status);
	}
}
/**
 * exiting_shell - exits the shell
 * @command: command to execute
 * @status: status of the shell
 *
 * Return: void
 */
void exiting_shell(char **command, int *status)
{
	freearray(command);
	exit(*status);
}
/**
 * printenv - prints the environment
 * @command: command to execute
 * @status: status of the shell
 *
 * Return: void
 */
void printenv(char **command, int *status)
{
	int counter;

	for (counter = 0; environ[counter]; counter++)
	{
		write(STDOUT_FILENO, environ[counter], _strlen(environ[counter]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freearray(command);
	(*status) = 0;
}
