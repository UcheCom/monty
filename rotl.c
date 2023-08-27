#include "monty.h"

/**
 * rotl - this rotates the stack to the top.
 * @head: double pointer to the head of the stack
 * @line: current line number
 *
 * Return: void
 */
void rotl(stack_t **head, unsigned int line)
{
	stack_t *end, *second;

	(void)line;

	if (*head && (*head)->next)
	{
		end = *head;
		while (end->next)
			end = end->next;

		second = (*head)->next;
		second->prev = NULL;
		end->next = *head;
		(*head)->prev = end;
		(*head)->next = NULL;
		*head = second;
	}
}
