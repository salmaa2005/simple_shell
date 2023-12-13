#include "shell.h"

/**
 * tokenizer - tokenizes a string
 * @line: string to tokenize
 * @delimiter: an array of delimiters (separators)
 *
 * Return: returns pointer to an array of strings
 */

char **tokenizer(char *line, char *delimiter)
{
	char **command = NULL;
	int i = 0, j = 0;

	if (!line)
		return (NULL);

	command = _strtok(line, delimiter);

	/* if memory allocation fails */
	if (command == NULL)
		return (NULL);

	while (command[i] != NULL)
		i++;

	command = realloc(command, sizeof(char *) * (i + 1));

	if (command == NULL)
		return (NULL);

	for (j = 0; j < i; j++)
	{
		command[j] = _strdup(command[j]);
		if (command[j] == NULL)
		{
			while (j > 0)
				free(command[--j]);
			free(command);
			return (NULL);
		}
	}
	return (command);
}
