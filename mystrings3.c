#include "mystrings.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
	return ('\0');
}
