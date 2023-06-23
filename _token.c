#include "monty.h"

/**
 * _token - for token command and value
 * @str: string
 * Return: 1 on success
 */
int _token(char *str)
{
	if (_newlineCheck(str) == 1)
		return (-1);

	gloVal.cmd = strtok(str, delim);
	if (gloVal.cmd[0] == '#')
		return (-1);
	if (gloVal.cmd[0] != '\0')
	{
		gloVal.value = strtok(NULL, delim);
		if (gloVal.value != NULL)
			gloVal.int_val = atoi(gloVal.value);
	}
	return (1);
}
