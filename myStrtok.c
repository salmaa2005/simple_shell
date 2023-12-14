#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * check_delimiter - checks if a character is a delimiter
 * @c: character to check
 * @delimiter: delimiter string
 *
 * Return: 1 if the character is a delimiter, 0 otherwise
 */
int check_delimiter(char c, const char *delimiter)
{
	int i = 0;

	if (delimiter == NULL)
		return (0);

	for (i = 0; delimiter[i] != '\0'; i++)
	{
		if (c == delimiter[i])
			return (1);
	}
	return (0);
}
/**
 * _strtok - splits a string into tokens
 * @string: string to split
 * @delimiter: delimiter string
 *
 * Return: a pointer to an array of tokens
 */
char **_strtok(char *string, const char *delimiter)
{
	int token_count = 0, j = 0, k = 0, i = 0, m = 0;
	char **tokens;

	if (string == NULL || string[0] == '\0')
		return (NULL);
	if (delimiter == NULL)
		delimiter = " ";
	for (i = 0; string[i] != '\0'; i++)
	{
		if (!check_delimiter(string[i], delimiter) &&
			(check_delimiter(string[i + 1], delimiter) ||
			 string[i + 1] == '\0'))
			token_count++;
	}
	if (token_count == 0)
		return (NULL);
	tokens = malloc((token_count + 1) * sizeof(char *));
	if (tokens == NULL)
		return (NULL);
	for (i = 0; j < token_count; j++)
	{
		while (check_delimiter(string[i], delimiter))
			i++;
		while (!check_delimiter(string[i + k], delimiter) &&
			   string[i + k] != '\0')
			k++;
		tokens[j] = malloc((k + 1) * sizeof(char));
		if (tokens[j] == NULL)
		{
			for (m = 0; m < j; m++)
				free(tokens[m]);
			free(tokens);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			tokens[j][m] = string[i++];
		tokens[j][k] = '\0';
	}
	tokens[j] = NULL;
	return (tokens);
}
/**
 * free_tokens - frees an array of tokens
 * @tokens: array of Tokens
 *
 * Return: returns void
 */
void free_tokens(char **tokens)
{
	int i = 0;

	if (tokens == NULL)
		return;

	for (i = 0; tokens[i] != NULL; i++)
		free(tokens[i]);

	free(tokens);
}
/**
 * print_tokens - prints an array of tokens
 * @tokens: array of tokens
 *
 * Return: returns void
 */
void print_tokens(char **tokens)
{
	int i = 0;

	if (tokens == NULL)
	{
		printf("Tokens: NULL\n");
		return;
	}

	printf("Tokens: ");
	for (i = 0; tokens[i] != NULL; i++)
	{
		printf("'%s' ", tokens[i]);
	}
	printf("\n");
}
