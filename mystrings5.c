#include "shell.h"
/**
 * _itoa - converts an integer to a string
 * @n: integer to be converted
 *
 * Return: pointer to a string
 */
char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
	{
		buffer[i++] = '0';
	}
	else
	{
		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	buffer[i] = '\0';
	reverse_string(buffer, i);
	return (_strdup(buffer));
}

/**
 * reverse_string - reverses a string
 * @str: string to be reversed
 * @len: length of the string
 *
 * Return: void
 */
void reverse_string(char *str, int len)
{
	int first = 0;
	int last = len - 1;
	char tmp;

	while (first < last)
	{
		tmp = str[first];
		str[first] = str[last];
		str[last] = tmp;
		first++;
		last--;
	}
}
