#include "monty.h"

/**
 * swap - this swaps the top 2 elements of the stack
 * @head: double pointer to the head of the stack
 * @line: current line number
 *
 * Return: void
 */
void swap(stack_t **head, unsigned int line)
{
	stack_t *end;
	unsigned int counter = 0;

	end = *head;
	while (end)
	{
		counter++;
		end = end->next;
	}
	if (counter < 2)
	{
		fprintf(stderr, SWAP_FAIL, line);
		_freevar();
		exit(EXIT_FAILURE);
	}
	end = *head;
	*head = (*head)->next;
	end->next = (*head)->next;
	end->prev = (*head);
	(*head)->next = end;
	(*head)->prev = NULL;
}
