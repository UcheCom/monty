#include "monty.h"

/**
 * rotr - this rotates the stack to the bottom.
 * @head: double pointer to the head of the stack
 * @line: current line number
 *
 * Return: void
 */

void rotr(stack_t **head, unsigned int line)
{
	stack_t *tmp, *end;

	(void)line;

	if (*head && (*head)->next)
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;

		end = tmp->prev;
		end->next = NULL;
		tmp->next = *head;
		(*head)->prev = tmp;
		tmp->prev = NULL;
		*head = tmp;
	}
}
