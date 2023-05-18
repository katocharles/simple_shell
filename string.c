#include "shell.h"

/**
 * _strcmp - a function that compares two strings
 *
 * @s1: string 1 to compare to string 2
 * @s2: string 2 against which string 1 is compared
 *
 * Return: 0 if s1 and s2 are equal
 *        negative integer if the stopping character
 *         in @s1 was less than the stopping character in @s2
 *        positive integer if the stopping character
 *         in @s1 was greater than the stopping character in @s2
 */

int _strcmp(char *s1, char *s2)
{
	int iterator = 0, response;

	/* iterate through src and compare it with dest */
	while (s1[iterator] != '\0' && s2[iterator] != '\0')
	{
		/* if they differ by a single character don't iterate further */
		if (s1[iterator] != s2[iterator])
		{
			/* difference between the two characters */
			response = s1[iterator] - s2[iterator];
			break;
		}
		else
		{
			response = s1[iterator] - s2[iterator];
		}
		iterator++;
	}

	return (response);
}

/**
 * _strcat - function that concatenates two strings.
 *
 * @dest: pointer to destination parameter
 * @src: pointer to source parameter
 *
 * Return: pointer to resulting string destination
 */

char *_strcat(char *dest, char *src)
{
	int d, s;

	d = 0;
	/*find the size of dest array*/
	while (dest[d])
		d++;

	/* iterate through each src array value without the null byte*/
	for (s = 0; src[s]; s++)
		/*append src[s] to dest[c] while overwriting the null byte in dest*/
		dest[d++] = src[s];

	return (dest);
}

/**
 * _strlen - calculates the length of the string
 *
 * @s: string parameter input
 *
 * Return: length of string
*/

int _strlen(char *s)
{
	int counter;

	for (counter = 0; *s != '\0'; ++s)
		++counter;

	return (counter);
}

/**
 * _strcpy - A function that copies a string.
 *
 * @dest: pointer to destination input buffer
 * @src: pointer to source input buffer
 * Return: pointer to destination
 */

char *_strcpy(char *dest, char *src)
{
	int i;
	int n = _strlen(src);

	/**
	 * iterate through src array where if there is no null byte
	 * among the first n bytes of source the string placed in dest will not be
	 * null terminated
	 */
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	/**
	 * if the length of source is less than n
	 * write additional null bytes to dest to
	 * ensure that a total of n bytes is written
	 */
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}

	return (dest);
}

