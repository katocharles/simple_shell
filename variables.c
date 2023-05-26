#include "shell.h"

/**
 * chain_delim - Tests whether a char is a chain delimiter.
 * @structs: Struct parameter
 * @buffer: the char buffer
 * @add: address of current position
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int chain_delim(info_t *structs, char *buffer, size_t *add)
{
	size_t n = *add;

	if (buffer[n] == '|' && buffer[n + 1] == '|')
	{
		buffer[n] = 0;
		n++;
		structs->cmd_buf_type = CMD_OR;
	}
	else if (buffer[n] == '&' && buffer[n + 1] == '&')
	{
		buffer[n] = 0;
		n++;
		structs->cmd_buf_type = CMD_AND;
	}
	else if (buffer[n] == ';') /* found end of this command */
	{
		buffer[n] = 0; /* replace semicolon with null */
		structs->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*add = n;
	return (1);
}

/**
 * con_chain_delim - Determines whether to continue chaining.
 * @structs: struct parameter
 * @buffer: the char buffer
 * @add: address of current position.
 * @n: The beginning of the buffer
 * @len: buffer length
 *
 * Return: Void
 */
void con_chain_delim(info_t *structs, char *buffer, size_t *add, size_t n, size_t len)
{
	size_t i = *add;

	if (structs->cmd_buf_type == CMD_AND)
	{
		if (structs->status)
		{
			buffer[n] = 0;
			i = len;
		}
	}
	if (structs->cmd_buf_type == CMD_OR)
	{
		if (!structs->status)
		{
			buffer[n] = 0;
			i = len;
		}
	}

	*add = i;
}

/**
 * new_alias - Changes the alias in newly tokenized string
 * @structs: Struct parameter
 *
 * Return: 1 if replaced or 0 upon failure.
 */
int new_alias(info_t *structs)
{
	int n;
	list_t *node;
	char *ptr;

	for (n = 0; n < 10; n++)
	{
		node = node_starts_with(structs->alias, structs->argv[0], '=');
		if (!node)
			return (0);
		free(structs->argv[0]);
		ptr = _strchr(node->str, '=');
		if (!ptr)
			return (0);
		ptr = _strdup(ptr + 1);
		if (!ptr)
			return (0);
		structs->argv[0] = ptr;
	}
	return (1);
}

/**
 * new_variables - Changes the variables in newly tokenized string
 * @structs: Struct parameters
 *
 * Return: 1 if replaced, 0 upon failure.
 */
int new_variables(info_t *structs)
{
	int n = 0;
	list_t *node;

	for (n = 0; structs->argv[n]; n++)
	{
		if (structs->argv[n][0] != '$' || !structs->argv[n][1])
			continue;

		if (!_strcmp(structs->argv[n], "$?"))
		{
			new_string(&(structs->argv[n]),
					_strdup(convert_number(structs->status, 10, 0)));
			continue;
		}
		if (!_strcmp(structs->argv[n], "$$"))
		{
			new_string(&(structs->argv[n]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(structs->env, &info->argv[n][1], '=');
		if (node)
		{
			new_string(&(structs->argv[n]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		new_string(&structs->argv[n], _strdup(""));

	}
	return (0);
}

/**
 * new_string - Changes old string to a revised string
 * @old: address of old string
 * @revised: new string
 *
 * Return: 1 if replaced, 0 upon failure
 */
int new_string(char **old, char *revised)
{
	free(*old);
	*old = revised;
          return (1);
}

