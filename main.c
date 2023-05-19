#include "shell.h"

/**
 * main - This is the main function of the program
 * it accepts two arguments
 * @argc: argument count
 * @argv: argument array
 * @env: environment variables
 * Return: returns zero.
 **/
int main(int argc, char *argv[], char **env)
{
	char *command;
	char *exit_text = "Sucessfully exited BasicShell...";

	/**
	 * create an infinite loop 
	 * This enables the prompt to re-occur until 
	 * an exit command is received or entered 
	 **/
	while(1)
	{
		/* prompt for user input */
		prompt();

		/* get typed input and store it */
		command = get_command();

		/* if no command entered exit */
		if (!command)
			exit(EXIT_SUCCESS);

		/* terminate on user exit command */
		if (_strcmp(command, "exit\n") == 0)
		{
			free(command);
			break;
		}

		/* just return entered command */
		write(STDOUT_FILENO, exit_text, 32);

		/* free allocated memory */
		free(command);
	}

	return (0);
}
