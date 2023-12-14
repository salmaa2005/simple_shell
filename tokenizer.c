#include "shell.h"
/**
 * tokenizer - splits a line into tokens
 * @line: input line
 *
 * Return: pointer to an array of tokens
 */
char **tokenizer(char *line)
{
	char *token, *tmp;
	char **command = NULL;
	int i = 0, j = 0;

	if (!line)
		return (NULL);
	tmp = _strdup(line);
	if (!tmp)
		return (NULL);
	token = _strtok(tmp, " \t\n");
	if (token == NULL)
	{
		free(tmp);
		return (NULL);
	}
	while (token)
	{
		i++;
		token = _strtok(NULL, " \t\n");
	}
	free(tmp);
	command = malloc(sizeof(char *) * (i + 1));
	if (!command)
		return (NULL);
	tmp = _strdup(line);
	if (!tmp)
	{
		free(command);
		return (NULL);
	}
	token = _strtok(tmp, " \t\n");
	while (token)
	{
		command[j] = _strdup(token);
		if (!command[j])
		{
			while (j > 0)
				free(command[--j]);
			free(command);
			free(tmp);
			return (NULL);
		}
		token = _strtok(NULL, " \t\n");
		j++;
	}
	free(tmp);
	command[i] = NULL;
	return (command);
}
