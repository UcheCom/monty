#include "monty.h"

/**
 * sub - this subtracts the elements
 * @head: double pointer to the head of the stack
 * @line: current line number
 *
 * Return: void
 */
void _sub(stack_t **head, unsigned int line)
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
		fprintf(stderr, SUB_FAIL, line);
		_freevar();
		exit(EXIT_FAILURE);
	}
	((*head)->next)->n -= (*head)->n;
	pop(head, line);
}
