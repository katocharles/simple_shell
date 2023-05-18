#include "shell.h"

/**
* get_command - copies user entered command
*
* Return: returns pointer to entered command
*/
char *get_command(void)
{
	char *line = NULL; /* pointer for the input line */
	char *command = NULL; /* pointer for concatenated command */
	char *pointer = NULL; /* pointer  for temp use in memory reallocation */

	size_t buffer_size = 0; /* allocated input buffer size */
	ssize_t line_length = 0;
	char pointerLength = 0;

	if ((line_length = getline(&line, &buffer_size, stdin)) != -1)
	{
		/* if command is NULL allocate memory */
		if (!command)
			command = malloc(line_length + 1); /* add 1 for null terminator*/
		else
		{
			/* reallocate memory to accommodate the new line */
			pointer = realloc(command, line_length + pointerLength + 1);

			if (pointer)
				command = pointer;
			else
			{
				/* free memory if reallocation fails */
				free(command);
				command = NULL;
			}
		}

		/* if command is NULL after memory reallocation send error */
		if (!command)
		{
			perror("Error reading command");
			return (NULL);
		}

		_strcpy(command + pointerLength, line);

		pointerLength += line_length;
	}

	return (command);
}

