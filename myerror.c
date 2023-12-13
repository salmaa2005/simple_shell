#include "shell.h"
/**
 * printerror - prints an error message
 * @name: name of the program
 * @cmd: command
 * @idx: index
 *
 * Return: void
 */
void printerror(char *name, char *cmd, int idx)
{
	char *index;
	char msg[] = ": not found\n";

	index = _itoa(idx);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, index, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, msg, _strlen(msg));

	free(index);
}
