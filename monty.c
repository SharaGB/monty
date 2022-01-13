#include "monty.h"
/**
 * fpush - Pushes an element to the stack.
 * @pila: Header of the list(stack)
 * @line_number: Line data
 */
void fpush(stack_t **pila, unsigned int line_number)
{
	stack_t *nn = malloc(sizeof(stack_t));

	if (!nn)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (!line_number)
	{
		printf("es acá\n");
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	nn->n = line_number;
	nn->prev = NULL;
	nn->next = *pila;
	*pila = nn;
	if (*pila)
	{
		(*pila)->prev = nn;
	}
}

/**
 * fpall - Prints all the values on the stack.
 * @pila: Header of the list(stack)
 * @data: Line data
 */
void fpall(stack_t **pila, unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp = *pila;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * fpint - Prints the value at the top of the stack.
 * @pila: Header of the list(stack)
 * @data: Line data
 */
void fpint(stack_t **pila, unsigned int line_number)
{
	if (!pila)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*pila)->n);
	}
}

/**
 * fpop - Removes the top element of the stack.
 * @pila: Header of the list(stack)
 * @data: Line data
 */
void fpop(stack_t **pila, unsigned int line_number)
{
	stack_t *stk = NULL;

	if (!*pila)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (stk->next)
	{
		stk = (*pila)->prev;
		*pila = (*pila)->next;
		free(stk);
		(*pila)->prev = NULL;
	}
	free(*pila);
	(*pila)->next--;
}
