#include "monty.h"

/**
 * pint - this prints the value at the top of the stack
 * @head: double pointer to the head of the stack
 * @line: current line number
 *
 */
void pint(stack_t **head, unsigned int line)
{
	if (*head == NULL)
	{
		fprintf(stderr, PINT_FAIL, line);
		_freevar();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
