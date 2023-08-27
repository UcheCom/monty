#include "monty.h"

/**
 * add_dnodeint - adds a new node at the top of a doubly linked list
 * @head: double pointer to the stack
 * @n: data to insert in the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	if (!head)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, MALLOC_FAIL);
		_freevar();
		exit(EXIT_FAILURE);
	}
	new->n = n;

	new->next = *head;
	new->prev = NULL;

	if (*head)
		(*head)->prev = new;

	*head = new;

	return (*head);
}

/**
 * free_dlistint - this frees a stack
 * @head: pointer to a node
 *
 * Return: nothing
 */
void free_dlistint(stack_t *head)
{
	stack_t *all;

	while ((all = head) != NULL)
	{
		head = head->next;
		free(all);
	}
}

/**
 * add_dnodeint_end - this adds a new node at the end of a stack
 * @head: double pointer of the head of the stack
 * @n: data to be inserted
 *
 * Return: a pointer to the stack or NULL if failed
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *end, *lst;

	if (head == NULL)
		return (NULL);
	end = malloc(sizeof(stack_t));
	if (!end)
	{
		fprintf(stderr, MALLOC_FAIL);
		_freevar();
		exit(EXIT_FAILURE);
	}
	end->n = n;
	end->next = NULL;
	if (*head == NULL)
	{
		end->prev = NULL;
		*head = end;
		return (*head);
	}
	lst = *head;
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = end;
	end->prev = lst;
	return (end);
}
