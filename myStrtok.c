#include "shell.h"
#include <stdlib.h>

/**
 * check_delimiter - checks if a character is a delimeter
 * @c: the character to be chaecked
 * @delimiter: an array of characters
 *
 * Return: 1 if c is a delimiter, 0 otherwise
 */
int check_delimiter(char c, char *delimiter)
{
	int i;

	for (i = 0; delimiter[i] != '\0'; i++)
	{
		if (c == delimiter[i])
			return (1);
	}
	return (0);
}
/**
 * _strtok - splits a string into tokens
 * @string: the string to be split
 * @delimiter: the delimiter string
 *
 * Return: a pointer to an array of strings
 */

char **_strtok(char *string, char *delimiter)
{
	int i, j, k, m;
	int token_count = 0;
	char **s;

	if (string == NULL || string[0] == 0)
		return (NULL);
	if (!delimiter)
		delimiter = " ";
	for (i = 0; string[i] != '\0'; i++)
		if (!check_delimiter(string[i], delimiter) &&
			(check_delimiter(string[i + 1], delimiter) || !string[i + 1]))
			token_count++;

	if (token_count == 0)
		return (NULL);

	s = malloc((1 + token_count) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < token_count; j++)
	{
		while (check_delimiter(string[i], delimiter))
			i++;
		k = 0;
		while (!check_delimiter(string[i + k], delimiter) && string[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = string[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
