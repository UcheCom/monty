#include "monty.h"

/**
 * mod - handles the mod instruction
 * @head: double pointer to the head of the stack
 * @line: current line number
 *
 * Return: void
 */
void mod(stack_t **head, unsigned int line)
{
	stack_t *temp;
	unsigned int counter = 0;

	temp = *head;
	while (temp)
	{
		counter++;
		temp = temp->next;
	}
	if (counter < 2)
	{
		fprintf(stderr, MOD_FAIL, line);
		_freevar();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, DIV_ZERO, line);
		_freevar();
		exit(EXIT_FAILURE);
	}
	((*head)->next)->n %= (*head)->n;
	pop(head, line);
}
