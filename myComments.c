#include "shell.h"

/**
 * ignore_comments - ignores comments
 * @comment: comment
 *
 * Return: void
 */

void ignore_comments(char *comment)
{
	int i;

	for (i = 0; comment[i] != '\0'; i++)
	{
		if (comment[i] == '#' && (!i || comment[i - 1] == ' '))
		{
			comment[i] = '\0';
			break;
		}
	}
}
