#include "shell.h"
/**
 * freearray - frees an array of strings (a 2d array)
 * @arr: the array to be freed
 *
 * Return: void
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
