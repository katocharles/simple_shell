#include "shell.h"

int main(int argc, char *argv[], char **env)
{
	/*create pointers to temp storage (buffer) and prompt*/
	char *buffer, *command_prompt = "BasicShell$ ";
	bool pipe = false;
	size_t buffer_length = 0;
	ssize_t size;
	pid_t pid;
	int status;

	while (true && !pipe) /* while loop enables prompt to re-occur */
	{
		/* Tests whether file descriptor comes from terminal or elsewhere */
		if (isatty(STDIN_FILENO) == 0)
			pipe = true;

		/* Write command prompt to the terminal */
		write(STDOUT_FILENO, command_prompt, 12);

		/* dynamically allocate enough space with getline */
		size = getline(&buffer, &buffer_length, stdin);

		/* check if space allocation failed */
		if (size == -1)
		{
			perror("Getline function error encountered");
			free(buffer);
			exit(EXIT_FAILURE);
		}

		/* Adding a null terminator because getline permanently alters the original string */
		if (buffer[size - 1] == '\n')
			(buffer[size - 1] = '\0');

		/* start a child process */
		pid = fork();

		/* check if starting child process failed */
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

	free(buffer);

	return (0);
}
