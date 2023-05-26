#include "shell.h"

/**
 * **strtoken - tokenizes the string. Ignores delimiter Repititions
 * @str: String to be tokenized
 * @delim: Delimiter of the string
 * Return: pointer to an array of strings, or NULL upon failure
 */

char **strtoken(char *str, char *delim)
{
	int a, b, c, n, len = 0;
	char **ptr;

         /*Provision for if the string is empty*/
	if (str == NULL || str[0] == 0)
		return (NULL);
        /*Provision for if there is no delimiter*/
	if (!delim)
		delim = " ";

	for (a = 0; str[a] != '\0'; a++)
		if (!is_delim(str[a], delim) && (is_delim(str[a + 1], delim) || !str[a + 1]))
			len++;

	if (len == 0)
		return (NULL);
	ptr = malloc((1 + len) * sizeof(char *));
	if (!ptr)
		return (NULL);
	for (a = 0, b = 0; b < len; b++)
	{
		while (is_delim(str[a], delim))
			a++;
		c = 0;
		while (!is_delim(str[a + c], delim) && str[a + c])
			c++;
		ptr[b] = malloc((c + 1) * sizeof(char));
		if (!ptr[b])
		{
			for (c = 0; c < b; c++)
				free(ptr[c]);
			free(ptr);
			return (NULL);
		}
		for (n = 0; n < c; n++)
			ptr[b][n] = str[a++];
		ptr[b][n] = 0;
	}
	ptr[b] = NULL;
	return (ptr);
}

/**
 * **strtoken2 - Tokenizes the string.
 * @str: String to be split
 * @delim: Delimeter
 * Return: Pointer to an array of strings, or NULL upon failure
 */
char **strtoken2(char *str, char delim)
{
	int a, b, c, n, len = 0;
	char **ptr;

        /*Provision for if the string is empty*/
	if (str == NULL || str[0] == 0)
		return (NULL);

	for (a = 0; str[a] != '\0'; a++)
		if ((str[a] != delim && str[a + 1] == delim) ||
				    (str[a] != delim && !str[a + 1]) || str[a + 1] == delim)
			len++;
	if (len == 0)
		return (NULL);
	ptr = malloc((1 + len) * sizeof(char *));
	if (!ptr)
		return (NULL);
	for (a = 0, b = 0; b < len; b++)
	{
		while (str[a] == delim && str[a] != delim)
			a++;
		c = 0;
		while (str[a + c] != delim && str[a + c] && str[a + c] != delim)
			c++;
		ptr[b] = malloc((c + 1) * sizeof(char));
		if (!ptr[b])
		{
			for (c = 0; c < b; c++)
				free(ptr[c]);
			free(ptr);
			return (NULL);
		}
		for (n = 0; n < c; n++)
			ptr[b][n] = str[a++];
		ptr[b][n] = 0;
	}
	ptr[b] = NULL;
	return (ptr);
}

