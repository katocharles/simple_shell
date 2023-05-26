#include "shell.h"

/**
 * free_ptr - Function NULL's address and frees the pointer.
 * @ptr: address of the pointer that is to be freed
 *
 * Return: 1 if freed or 0 upon failure.
 */
int free_ptr(void **ptr)
{
/*Takes into account both the string and pointer to the string*/
	if (ptr && *ptr)
	{
/*Frees the pointer and makes the address equal to NULL*/
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

