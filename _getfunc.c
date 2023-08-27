#include "monty.h"

/**
 * _getfunc - this selects the right function
 * @op: instructions passed to the main
 *
 * Return: pointer to the funciton associated or NULL if not found
 */
void (*_getfunc(char *op))(stack_t **stack, unsigned int line_number)
{
	instruction_t func_lists[] = {
		{"push", push}, {"swap", swap},
		{"pall", pall}, {"nop", nop},
		{"pint", pint}, {"div", div},
		{"pop", pop}, {"mod", mod},
		{"pchar", pchar}, {"rotl", rotl},
		{"stack", stack}, {"queue", queue},
		{"add", add}, {"sub", sub},
		{"mul", mul}, {"pstr", pstr},
		{"rotr", rotr},
		{NULL, NULL}
	};

	int i;

	for (i = 0; func_lists[i].opcode; i++)
	{
		if (strcmp(func_lists[i].opcode, op) == 0)
			break;
	}
	return (func_lists[i].f);
}
