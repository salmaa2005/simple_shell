#include "shell.h"

/**
 * _strstr - locates a specfic substring
 * @haystack: the string to be searched for
 * @needle: the substring to be located
 *
 * Return: returns a pointer
 */

char *_strstr(char *haystack, char *needle)
{
    while (*haystack) {
        char *hay = haystack;
        char *nee = needle;

        while (*haystack && *nee && *haystack == *nee) {
            haystack++;
            nee++;
        }

        if (!*nee) {
            return hay;  /* needle found in haystack */
        }

        haystack = hay + 1;  /* reset haystack to the next character */
    }

    return NULL;  /* needle not found */
}



/**
 * _strdup - duplicates a specfic string
 * @str: the string to be duplicated
 *
 * Return: pointer to that specfic duplicated string
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *ret;

	if (str == NULL)
		return NULL;
	while (*str++)
		len++;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return NULL;
	for (len++; len--;)
		ret[len] = *(--str);
	return (ret);
}

