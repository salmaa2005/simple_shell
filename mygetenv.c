#include "shell.h"

/**
 * _getenv - gets the value of an environment variable
 * @variable: the name of the environment variable
 *
 * Return: the value of the environment variable
 */
char *_getenv(char *variable)

{
	char *tmp;
	char *key;
	char *value;
	char *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");

		if (_strcmp(key, variable) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(tmp);
			return (env);
		}
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}
