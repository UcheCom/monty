#include "monty.h"

/**
 * pop - this removes the top element of the stack
 * @head: double pointer to the head of the stack
 * @line: current line number
 *
 * Return: void
 */
void pop(stack_t **head, unsigned int line)
{
	stack_t *up;

	if (!head || !*head)
	{
		fprintf(stderr, POP_FAIL, line);
		_freevar();
		exit(EXIT_FAILURE);
	}
	up = *head;
	*head = (*head)->next;
	free(up);
}
