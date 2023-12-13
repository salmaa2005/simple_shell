#include "shell.h"

/**
 * _strstr - locates a substring
 * @haystack: the string to be searched for
 * @needle: the substring to be located at
 *
 * Return: returns a pointer to the substring
 */

char *_strstr(char *haystack, char *needle)
{
	while (*haystack)
	{
		char *hay = haystack;
		char *nee = needle;

		while (*haystack && *nee && *haystack == *nee)
		{
			haystack++;
			nee++;
		}

		if (!*nee)
		{
			return (hay); /* needle found in haystack */
		}

		haystack = hay + 1; /* reset haystack to the next character */
	}

	return (NULL); /* needle not found */
}

/**
 * _strdup - duplicates a string
 * @string: the specfic string to duplicate
 *
 * Return: pointer
 */
char *_strdup(const char *string)
{
	int len = 0;
	char *ret;

	if (string == NULL)
		return (NULL);
	while (*string++)
		len++;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	for (len++; len--;)
		ret[len] = *--string;
	return (ret);
}
