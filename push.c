#include "monty.h"

/**
 * push - handles the push instruction
 * @stack: double pointer to the stack
 * @line_number: number of the line in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *nw;
	int num = 0, x;

	if (uvar.toks[1] == NULL)
	{
		dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
		free_all(1);
		exit(EXIT_FAILURE);
	}

	for (x = 0; uvar.toks[1][x]; x++)
	{
		if (isalpha(uvar.toks[1][x]) != 0)
		{
			dprintf(STDERR_FILENO, PUSH_FAIL, line_number);
			free_all(1);
			exit(EXIT_FAILURE);
		}
	}
	num = atoi(uvar.toks[1]);

	if (uvar.qs_flag == 0)
		nw = add_dnodeint(stack, num);
	else if (uvar.qs_flag == 1)
		nw = add_dnodeint_end(stack, num);
	if (!nw)
	{
		dprintf(STDERR_FILENO, MALLOC_FAIL);
		free_all(1);
		exit(EXIT_FAILURE);
	}
}
