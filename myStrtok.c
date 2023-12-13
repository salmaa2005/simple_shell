#include "shell.h"
#include <stdbool.h>

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
 * count_tokens - counts the number of tokens in a string
 * @string: the string to be tokenized
 * @delimiter: an array of characters
 *
 * Return: the number of tokens
 */

int count_tokens(char *string, char *delimiter)
{
	int token_count = 0;
	int i;

	for (i = 0; string[i] != '\0'; i++)
	{
		if (check_delimiter(string[i], delimiter))
			token_count++;
	}
	return (token_count);
}

/**
 * _strtok - divides a string into tokenized_string
 * @string: the string to be tokenized
 * @delimiter: an array of characters
 *
 * Return: an array of pointers to the tokenized string
 */
char **_strtok(char *string, char *delimiter)
{
	char **tokenized_string;
	int token_count = 0;
	int i, row = 0, column;

	if (string == NULL)
		return (NULL);

	token_count = count_tokens(string, delimiter);

	tokenized_string = (char **)malloc(sizeof(char *) * (token_count + 1));

	for (i = 0; string[i] != '\0'; i++)
	{
		if (!check_delimiter(string[i], delimiter))
		{
			int token_length = 1;

			while (string[i + token_length] != '\0' &&
				   !check_delimiter(string[i + token_length], delimiter))
				token_length++;

			tokenized_string[row] =
				(char *)malloc((token_length + 1) * sizeof(char));
			if (tokenized_string[row] == NULL)
				return (NULL);

			strncpy(tokenized_string[row], string + i, token_length);
			tokenized_string[row][token_length] = '\0';

			row++;
			i += token_length - 1;
		}
	}

	tokenized_string[row] = NULL;
	return (tokenized_string);
}
