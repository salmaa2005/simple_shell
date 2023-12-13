#include "shell.h"
char **tokenizer(char *line)
{
	char *token, *tmp;
	char **command = NULL;
	int i, j;

	if (!line)
		return (NULL);

	tmp = _strdup(line);

	if (!tmp)
		return (NULL);
	token = strtok(tmp, " \t\n");
	if (token == NULL)
	{
		free(tmp);
		return (NULL);
	}
	while (token)
	{
		i++;
		token = strtok(NULL, " \t\n");
	}
	free(tmp);
	command = malloc(sizeof(char *) * (i + 1));
	if (!command)
	{
		return (NULL);
	}
	tmp = _strdup(line); /*Duplicate the input line before tokenizing*/
	if (!tmp)
	{
		free(command);
		return (NULL);
	}
	token = strtok(tmp, " \t\n");
	while (token)
	{
		command[j] = _strdup(token);
		if (!command[j])
		{ /*Free memory allocated so far */
			while (j > 0)
				free(command[--j]);
			free(command);
			free(tmp);
			return (NULL);
		}
		token = strtok(NULL, " \t\n");
		j++;
	}
	free(tmp);
	command[i] = NULL;
	return (command);
}
