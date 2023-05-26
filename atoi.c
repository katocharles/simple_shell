#include "shell.h"

/**
 * inter_mode- Checks whether the shell is in interactive mode
 * @structs: Struct parameter address
 *
 * Return: 1 if interactive mode, 0 upon failure
 */
int inter_mode(info_t *structs)
{
	/*Return this only if the shell is in interactive mode.*/
	return (isatty(STDIN_FILENO) && structs->readfd <= 2);
}

/**
 * is_delim - checks whether a character is a delimeter
 * @letter: the character to check
 * @delim: Delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char letter, char *delim)
{
	/*While loop that takes into account delimiters*/
	while (*delim)
		if (*delim++ == letter)
			return (1);
	return (0);
}

/**
 * _isalpha - checks whether character is an alphabetic character
 * @letter: The character to input
 * Return: 1 if c is alphabetic, 0 upon failure
 */

int _isalpha(int letter)
{
	/*Condition to identify whether the character is a letter*/
	if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'))
		return (1);
	else/* If it is not a letter return 0*/
		return (0);
}

/**
 * _atoi - Built in function that converts a string to an integer
 * @str: the string to be converted to an integer.
 * Return: 0 if no numbers are present or converted string if numbers are present.
 */

int _atoi(char *str)
{
	int n, output, sym = 1, flag = 0;
	unsigned int end = 0;

	for (n = 0; str[n] != '\0' && flag != 2; n++)
	{
		if (str[n] == '-')
			sym *= -1;

		if (str[n] >= '0' && str[n] <= '9')
		{
			flag = 1;
			end *= 10;
			end += (str[n] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sym == -1)
		output = -end;
	else
		output = end;

	return (output);
}

