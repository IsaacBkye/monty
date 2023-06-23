#include "monty.h"

/**
 * _find - Find operator
 * @head: pointer to stack
 * Return: 1 on success
 */

int _find(stack_t **head)
{
	int i = 0;

	instruction_t f_ope[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL},
	};

	while (f_ope[i].opcode != NULL)
	{
		if (strcmp(gloVal.cmd, f_ope[i].opcode) == 0)
		{
			f_ope[i].f(head, gloVal.line_number);
			return (1);
		}
		i++;
	}
	fprintf(stdout, "L%d: unknown instruction %s\n",
		gloVal.line_number, gloVal.cmd);
	gloVal.ret_val = -1;
	return (-1);
}
