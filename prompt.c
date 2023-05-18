#include "shell.h"

/**
* prompt - function that prints $ to prompt user for input
* Return: returns nothing
*/
void prompt(void)
{
	char *command_prompt = "BasicShell$ ";

	/* Write command prompt to the terminal */
		write(STDOUT_FILENO, command_prompt, 12);
}

