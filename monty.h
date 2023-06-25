#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#define delim "\n\r\t "
#define UNUSED(x) (void)(x)
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO notrebloh project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO notrebloh project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct vars - global variables
 * @lineptr: getline arg
 * @line_number: line number getline reads
 * @value: value of second argument
 * @int_val: value to int
 * @cmd: string of first argument in file
 * @ret_val: return
 */
typedef struct vars
{
	char *lineptr;
	unsigned int line_number;
	char *value;
	int int_val;
	char *cmd;
	int ret_val;
	char *flag;
} va_t;

extern va_t gloVal;
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void _free(stack_t *head);
int _find(stack_t **head);
int _token(char *str);
int _checkVal(char *str);
int _listLen(stack_t **h);
int _newlineCheck(char *str);
#endif
