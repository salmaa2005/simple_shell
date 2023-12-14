#include "shell.h"
#include <stdio.h>
#include <string.h>
/**
 * _strtok - tokenizes a string
 * @string: string to tokenize
 * @delimiters: delimiters
 *
 * Return: token
 */

char *_strtok(char *string, const char *delimiters)
{
	static char *current_tok;
	char *start_tok;

	if (string != NULL)
	{
		current_tok = string;
	}
	else
	{
		if (current_tok == NULL)
		{
			return (NULL);
		}
	}

	while (*current_tok && strchr(delimiters, *current_tok))
	{
		current_tok++;
	}

	if (*current_tok == '\0')
	{
		current_tok = NULL;
		return (NULL);
	}
	start_tok = current_tok;
	while (*current_tok && !strchr(delimiters, *current_tok))
	{
		current_tok++;
	}

	if (*current_tok != '\0')
	{
		*current_tok = '\0';
		current_tok++;
	}

	return (start_tok);
}
