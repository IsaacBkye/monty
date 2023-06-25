#include "monty.h"
#include <stdio.h>
va_t gloVal;
/**
 * main - monty interpreter
 * @argc: arg count
 * @argv: arg values
 * Return: return -1 if failed, else 1
 */
int main(int argc, char **argv)
{
	FILE *fp;
	stack_t *head = NULL;
	int token_ret = 0;
	ssize_t read = 0;
	size_t len = 0;

	gloVal.lineptr = NULL;
	gloVal.line_number = 0;
	if (argc != 2)
	{
		fprintf(stdout, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stdout, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&(gloVal.lineptr), &len, fp) != -1))
	{
		gloVal.line_number++;
		token_ret = _token(gloVal.lineptr);
		if (token_ret != -1)
		{
			_find(&head);
			if (gloVal.ret_val == -1)
			{
				free(gloVal.lineptr);
				_free(head);
				fclose(fp);
				exit(EXIT_FAILURE);
			}
		}
	}
	free(gloVal.lineptr); _free(head); fclose(fp);
	return (gloVal.ret_val);
}
