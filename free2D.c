#include "shell.h"
/**
 * freearray - frees a 2d array
 * @arr: array of strings (2d array)
 * Return: returns void
 */
void freearray(char **arr)

{
	int i;

	if (!arr)
		return;

	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
		arr[i] = NULL;
	}

	free(arr), arr = NULL;
}
