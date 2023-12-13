#include "shell.h"

/**
 * _strncat - cocatenates two strings
 * @dest: a pointer that points to an array of characters
 * @src: a pointer that points to an array of characters
 * @n: an integer that determines the number of characters to be concatenated
 *
 * Return: returns void
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0, s_length = 0, d_length = 0;

	while (src[s_length] != '\0')
		s_length++;
	while (dest[d_length] != '\0')
		d_length++;
	for (i = d_length; i < (n + d_length); i++)
	{
		if (src[j] != '\0')
		{
			dest[i] = src[j];
			j++;
		}
		else
			break;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: a pointer that points to an array of characters
 * @s2: a pointer that points to an array of characters
 *
 * Return: returns an integer
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, cmp;

	while (1)
	{
		cmp = s1[i] - s2[i];
		if (s1[i] == '\0' || s2[i] == '\0' || cmp != 0)
			return (cmp);
		i++;
	}
}

/**
 * _strchr - locates a character in a string
 * @s: a pointer that points to an array of characters
 * @c: the character to be searched for
 *
 * Return: returns a pointer to an index
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
			return (s + i);
	}
	return (NULL);
}

/**
 * _memset - fills memory with a constant byte
 * @s: a pointer that points to an array of characters
 * @b: the character to replace
 * @n: an integer that determines the replaced indeces
 * Return: returns a pointer to an array of characters
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}

/**
 * _memcpy - copies a memory area
 * @src: a pointer that points to an array of characters
 * @dest: a pointer that points to an array of characters
 * @n: the number of indeces to be replaced
 *
 * Return: returns a pointer to an array of characters
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
