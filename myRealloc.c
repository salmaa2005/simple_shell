#include "shell.h"

/**
 * _realloc - reallocates a memory block using malloc and free
 * @void_pointer: pointer to the memory allocated previously by malloc
 * @old_s: size of the pre-allocated memory
 * @new_size: size of the reallocated memory
 *
 * Return: a void pointer to the reallocated memory
 */

void *_realloc(void *void_pointer, unsigned int old_s, unsigned int new_size)
{
	char *newly_allocated;

	if (void_pointer == NULL)
		return (malloc(new_size));

	if (new_size == 0)
		return (free(void_pointer), NULL);

	if (new_size == old_s)
		return (void_pointer);

	newly_allocated = (char *)malloc(new_size);

	if (newly_allocated == NULL)
		return (NULL);

	if (old_s > new_size)
		old_s = new_size;
	while (old_s--)
		newly_allocated[old_s] = ((char *)void_pointer)[old_s];
	free(void_pointer);
	return (newly_allocated);
}
