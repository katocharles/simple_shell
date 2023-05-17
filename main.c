#include "shell.h"

int main(int argc, char *argv[], char **env)
{
	char *buff, *command_prompt = "BasicShell$ ";
	bool pipe = false;
	size_t buff_len = 0;
	ssize_t size;
	pid_t pid;
	int status;

	while (true && !pipe) /* while loop enables prompt to reoccour */
	{
		/* Tests whether file descriptor comes from terminal or elsewhere */
		if (isatty(STDIN_FILENO) == 0)
			pipe = true;

		write(STDOUT_FILENO, command_prompt, 12);
		/* Writes the command prompt to the terminal */

		size = getline(&buff, &buff_len, stdin);
		/* In case it Returns an Error: */
		if (size == -1)
		{
			perror("Getline function error encountered");
			free(buff); /* getline allocates space dynamically */
			exit(EXIT_FAILURE);
		}
		if (buff[size - 1] == '\n')
			(buff[size - 1] = '\0');
		/* Adding a null terminator because getline permanently alters the original string */

		pid = fork();
		/* In case it Returns an Error */
		if (pid == -1)
		{
			perror("Fork function error encountered");
			exit(EXIT_FAILURE);
		}
		/* if (pid == -1)
		 * insert execve function here.
		 */
		if (waitpid(pid, &status, 0) == -1)
		{
			/* enables parent process to wait for the child process to terminate */
			/* In case it Returns an Error */
			perror("Wait function error encountered");
			exit(EXIT_FAILURE);
		}
	}
	free(buff);
	return (0);
}
