#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: is a pointer to the first index of the string
 *
 * Return: returns the length of the string
 */
size_t _strlen(char *s)
{
	size_t i, count;

	count = 0;

	for (i = 0; s[i] != '\0'; i++)
		count++;
	return (count);
}
/**
 * _putchar - writes the character c to stdout
 * @c: the character to be printed
 *
 * Return: if successful retiurns 1, otherwise -1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string, followed by a new line, to stdout
 * @str: a pointer to a string (array of characters)
 *
 * Return: returns void
 */
void _puts(char *str)
{
	int i, j;

	int count = 0;

	for (j = 0; str[j] != '\0'; j++)
		count++;
	for (i = 0; i < count; i++)
		_putchar(str[i]);
	_putchar('\n');
}

/**
 * _strcat - concatenates two strings
 * @dest: is a pointer to a string
 * @src: is a pointer to a string
 *
 * Return: a pointer to an array of characters
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0, s_length = 0, d_length = 0;

	while (dest[d_length] != '\0')
		d_length++;
	while (src[s_length] != '\0')
		s_length++;
	for (i = d_length; i < (s_length + d_length); i++)
	{
		dest[i] = src[j];
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
