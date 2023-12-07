#include "shell.h"

/**
 * _strstr - locates a substring
 * @haystack: the string to be searched
 * @needle: the substring to be located
 *
 * Return: returns a pointer
 */

char *_strstr(char *haystack, char *needle)
{
    while (*haystack) {
        char *h = haystack;
        char *n = needle;

        while (*haystack && *n && *haystack == *n) {
            haystack++;
            n++;
        }

        if (!*n) {
            return h;  /* needle found in haystack */
        }

        haystack = h + 1;  /* reset haystack to the next character */
    }

    return NULL;  /* needle not found */
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	for (len++; len--;)
		ret[len] = *--str;
	return (ret);
}


