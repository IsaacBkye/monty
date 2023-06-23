#include "monty.h"
/**
 * _swap - swap values of the top elements of a linked list
 * @stack: pointer
 * @line_number: arg
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int len = 0;

	len = _listLen(stack);

	if (len < 2 || stack == NULL || *stack == NULL)
	{
		fprintf(stdout, "L%d: can't swap, stack too short\n",
			line_number);
		gloVal.ret_val = -1;
		return;
	}
	else
	{
		temp = (*stack)->next;
		(*stack)->prev = temp;
		(*stack)->next = temp->next;
		temp->prev = NULL;
		temp->next = *stack;
		*stack = temp;
	}
}
/**
 * _nop - nothing
 * @stack: pointer to pointer
 * @line_number: arg
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	UNUSED(stack);
	UNUSED(line_number);
}
/**
 * _listLen - total number of elements in linked list
 * @h: pointer to first node
 * Return: returns number of elements
 */
int _listLen(stack_t **h)
{
	int i = 0;
	stack_t *current;

	current = *h;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}
/**
 * _free - frees node
 * @head: pointer to first node
 */

void _free(stack_t *head)
{
	stack_t *current;

	while (head)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
/**
 * _newlineCheck - checks if the first char is a newline after first spaces
 * @str: takes a string
 * Return: 1 if it's a new line else 0
 */
int _newlineCheck(char *str)
{
	int i = 0;

	if (str[i] == '\n')
		return (1);

	while (str[i])
	{
		if (str[i] != ' '  || str[i + 1] != ' ')
			break;
		i++;
	}
	i++;
	if (str[i] == '\n')
		return (1);
	else
		return (0);
}
/**
 * _checkVal - checks if each value is a digit
 * @str: takes the value
 * Return: -1 if one of the values is not digit, else 1
 */
int _checkVal(char *str)
{
	int i = 0;

	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] > 47 && str[i] < 58)
			i++;
		else
			return (-1);
	}
	return (1);
}
