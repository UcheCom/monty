#include "monty.h"

/**
 * pall - this handles the pall instruction
 * @stack: double pointer to the stack
 * @line_number: number of the line in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (*stack)
		print_dlistint(*stack);
}
