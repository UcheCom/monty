#include "monty.h"
#include "lists.h"

/**
 * _getfunc - this selects the right function
 * @tokenised: line from the bytecode file passed to main
 *
 * Return: pointer to the selected function, or NULL on failure
 */
void (*_getfunc(char **tokenised))(stack_t **, unsigned int)
{
	instruction_t func_arr[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};

	int o_codes = 17, x;

	for (x = 0; x < o_codes; x++)
	{
		if (strcmp(func_arr[x].opcode, tokenised[0]) == 0)
		{
			return (func_arr[x].f);
		}
	}
	return (NULL);
}
