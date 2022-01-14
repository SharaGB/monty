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
		error_handler("Error: malloc failed", line_number);
	}
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
		error_handler("can't pint, stack empty", line_number);
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
		error_handler("can't pop an empty stack", line_number);
	}
	*stack = (*stack)->prev;
	if ((*stack) != NULL)
	{
		(*stack)->next = NULL;
	}
	free(stk);

}

/**
 * fswap - Swaps the top two elements of the stack.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void fswap(stack_t **stack, unsigned int line_number)
{
	int top = 0;

	if (!*stack || !(*stack)->prev)
	{
		error_handler("can't swap, stack too short", line_number);
	}
	top = (*stack)->n;
	(*stack)->n = (*stack)->prev->n;
	(*stack)->prev->n = top;
}
