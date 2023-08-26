# ifndef MONTY_H
# define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef stack_t dlistint_t;

/* _listfuncs.c */
size_t dlistint_len(const dlistint_t *h);
dlistint_t *add_dnodeint(dlistint_t **head, const int n);
size_t print_dlistint(const dlistint_t *h);
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);

/* _listfuncs1.c */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);
void free_dlistint(dlistint_t *head);

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct ags_s - structure of arguments from main
 * @argv: name of the file from the command line
 * @argc: number of arguments from main
 * @line_number: number of the current line in the file
 *
 * Description: arguments passed to main from the command line
 * used in various functions, arranged in a struct for clarity purpose.
 */
typedef struct ags_s
{
	char *argv;
	int argc;
	unsigned int line_number;
} ags_t;

/**
 * struct dat_s - structure of the global variable
 * @line: line from the file
 * @toks: parsed line
 * @stack: pointer to the stack
 * @ptr: file pointer
 * @qs_flag: flag for queue or stack
 */
typedef struct dat_s
{
	char *line;
	char **toks;
	stack_t *stack;
	FILE *ptr;
	int qs_flag;
} dat_t;

extern dat_t uvar;

#define UVAR_INIT {NULL, NULL, NULL, NULL, 0}

#define USAGE "USAGE: monty file\n"
#define FILE_ERROR "Error: Can't open file %s\n"
#define UNKNOWN "L%u: unknown instruction %s\n"
#define MALLOC_FAIL "Error: malloc failed\n"
#define PUSH_FAIL "L%u: usage: push integer\n"
#define PINT_FAIL "L%u: can't pint, stack empty\n"
#define POP_FAIL "L%u: can't pop an empty stack\n"
#define SWAP_FAIL "L%u: can't swap, stack too short\n"
#define ADD_FAIL "L%u: can't add, stack too short\n"
#define SUB_FAIL "L%u: can't sub, stack too short\n"
#define DIV_FAIL "L%u: can't div, stack too short\n"
#define DIV_ZERO "L%u: division by zero\n"
#define MUL_FAIL "L%u: can't mul, stack too short\n"
#define MOD_FAIL "L%u: can't mod, stack too short\n"
#define PCHAR_FAIL "L%u: can't pchar, stack empty\n"
#define PCHAR_RANGE "L%u: can't pchar, value out of range\n"

/******** main.c ***********/
void monty(ags_t *args);

/* get_func.c */
void (*_getfunc(char **tokenised))(stack_t **, unsigned int);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

/* mfree.c */
void free_all(int f_all);
void e_free(char **args);

/* strings.c */
int _wordcount(char *s);
char **strtow(char *s);

/* _getline function */
ssize_t _getline(char **line, size_t *n, FILE *stream);


# endif /* MONTY_H */
