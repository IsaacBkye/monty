#include "monty.h"
/**
 * _push - push value
 * @stack: pointer
 * @line_number: arg
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stdout, "Error: malloc failed\n");
		gloVal.ret_val = -1;
		return;
	}
	if (gloVal.value == NULL || _checkVal(gloVal.value) == -1)
	{
		fprintf(stdout, "L%d: usage: push integer\n", line_number);
		free(new);
		gloVal.ret_val = -1;
		return;
	}

	gloVal.int_val = atoi(gloVal.value);
	new->n = gloVal.int_val;
	new->prev = NULL;

	if (*stack == NULL)
		new->next = NULL;
	else
		new->next = *stack;
	if (new->next != NULL)
		new->next->prev = new;
	*stack = new;
}
/**
 * _pall - print stack  elements
 * @stack:  pointer
 * @line_number: arg
 */
void _pall(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *current;

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * _pint - Print value at the top of a stack
 * @stack: pointer
 * @line_number: arg
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stdout, "L%d: can't pint, stack empty\n", line_number);
		gloVal.ret_val = -1;
		return;
	}
	printf("%d\n", (*stack)->n);
}
/**
 * _add - Adder 
 * @stack: head of stack
 * @line_number: unsigned int arg
 *
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int len = 0;

	len = _listLen(stack);
	if (len < 2 || stack == NULL || *stack == NULL)
	{
		fprintf(stdout, "L%d: can't add, stack too short\n",
			line_number);
		gloVal.ret_val = -1;
		return;
	}
	else
	{
		temp = *stack;
		temp->next->n += temp->n;
		temp->next->prev = NULL;
		*stack = temp->next;
		free(temp);
	}
}
/**
 * _pop - remove node at head of stack
 * @stack: pointer
 * @line_number: arg
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stdout, "L%d: can't pop an empty stack\n",
			line_number);
		gloVal.ret_val = -1;
		return;
	}
	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
	}
	else
	{
		temp = (*stack)->next;
		(*stack) = temp;
		temp = temp->prev;
		(*stack)->prev = NULL;
		free(temp);
	}
}
