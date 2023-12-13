#include "shell.h"

/**
 * _strcpy - function that copies the string into another array
 * @src: a pointer that points to an array of characters
 * @dest: a pointer that points to an array of characters
 *
 * Return: returns an array of characters
 */
char *_strcpy(char *dest, char *src)
{
	int i, length = 0;

	while (src[length] != '\0')
		length++;
	for (i = 0; i <= length; i++)
		dest[i] = src[i];
	return (dest);
}

/**
 * _strspn - gets the length of a prefix substring
 * @s: a pointer that points to an array of characters
 * @accept: a pointer that points to an array of characters
 *
 * Return: Returns the number of bytes in s which consist of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j, count = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != ' ')
		{
			for (j = 0; accept[j] != '\0'; j++)
			{
				if (accept[j] == s[i])
					count++;
			}
		}
		else
			return (count);
	}
	return (count);
}

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: a pointer that points to an array of characters
 * @accept: a pointer that points to an array of characters
 *
 * Return: returns a pointer to an array of characters
 */
char *_strpbrk(char *s, char *accept)
{
	int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
				return (s + i);
		}
	}
	return (NULL);
}

/**
 * _strncpy - copies a specific number of chars into a string
 * @destination: an array of characters
 * @source: an array of characters
 * @char_number: the number of chars to be copied
 *
 * Return: returns a pointer to an array of chars
 */

char *_strncpy(char *destination, char *source, int char_number)
{
	int i = 0, j;
	char *return_string = destination;

	while (source[i] != '\0' && i < char_number)
	{
		destination[i] = source[i];
		i++;
	}

	if (i < char_number)
	{
		j = i;
		while (j < char_number)
		{
			destination[j] = '\0';
			j++;
		}
	}
	return (return_string);
}
