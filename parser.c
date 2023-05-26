#include "shell.h"

/**
 * exe_file - Function determines whether a file is an executable.
 * @structs: Struct parameters
 * @path: path to the file
 *
 * Return: 1 if true, 0 upon failure
 */
int exe_file(info_t *structs, char *path)
{
	struct stat n;

	(void)structs;
	if (!path || stat(path, &n))
		return (0);

	if (n.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * new_chars - duplicates characters in the original string
 * @strpath: the PATH string
 * @start: starting index
 * @stop: stopping index
 *
 * Return: pointer to new buffer
 */
char *new_chars(char *strpath, int start, int stop)
{
	static char bufffer[1024];
	int n = 0, i = 0;

	for (i = 0, n = start; n < stop; n++)
		if (strpath[n] != ':')
			buffer[i++] = strpath[n];
	buffer[i] = 0;
	return (buffer);
}

/**
 * find_path - finds the executable in the PATH string
 * @structs: Struct parameter
 * @strpath: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *structs, char *strpath, char *cmd)
{
	int n = 0, current_char = 0;
	char *path;

	if (!strpath)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (exe_file(structs, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!strpath[n] || strpath[n] == ':')
		{
			path = new_chars(strpath, current_char, n);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (exe_file(info, path))
				return (path);
			if (!strpath[n])
				break;
			current_char = n;
		}
		n++;
	}
	return (NULL);
}

