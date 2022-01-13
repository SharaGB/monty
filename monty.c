#include "monty.h"
/**
 * fpush - Pushes an element to the stack.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void fpush(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *nn = malloc(sizeof(stack_t));

	if (!nn)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	/*if (!line_number)
	{
		printf("es acá\n");
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}*/
	if (!*stack)
	{
		nn->n = global;
		nn->prev = NULL;
		nn->next = NULL;
		*stack = nn;
	}
	else
	{
		nn->n = global;
		nn->next = NULL;
		(*stack)->next = nn;
		nn->prev = *stack;
		*stack = nn;
	}
}

/**
 * fpall - Prints all the values on the stack.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void fpall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
	}
}

/**
 * fpint - Prints the value at the top of the stack.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void fpint(stack_t **stack, unsigned int line_number)
{
	if (!stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}
}

/**
 * fpop - Removes the top element of the stack.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void fpop(stack_t **stack, unsigned int line_number)
{
	stack_t *stk = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (stk->next)
	{
		*stack = (*stack)->next;
		free(stk);
		(*stack)->prev = NULL;
	}
	free(*stack);
	*stack = NULL;
}

/**
 * fswap - Swaps the top two elements of the stack.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void fswap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	int len = 0;

	len = _strlen(*stack);
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->prev = NULL;
	if (tmp->next)
	{
		tmp->next->prev = *stack;
	}
	(*stack)->prev = tmp;
	tmp->next = *stack;
	*stack = tmp;
}
