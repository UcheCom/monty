#include "monty.h"

/**
 * add - handles the add instruction
 * @head: double pointer to the head of the stack
 * @line: current line number
 *
 * Return: nothing
 */
void add(stack_t **head, unsigned int line)
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
		fprintf(stderr, ADD_FAIL, line);
		_freevar();
		exit(EXIT_FAILURE);
	}
	((*head)->next)->n += (*head)->n;
	pop(head, line);
}
