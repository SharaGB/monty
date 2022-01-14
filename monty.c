#include "monty.h"
/**
 * f_push - Pushes an element to the stack.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void f_push(stack_t **stack, unsigned int line_number)
{
	char *digit = NULL;
	char *delimiter = " \t\n";
	int i = 0;

	digit = strtok(NULL, delimiter);
	if (!digit || is_digit(digit))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = atoi(digit);
	if (!add_node(stack, i))
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	global.size++;
}

/**
 * f_pall - Prints all the values on the stack.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void f_pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp = *stack;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
	}
}

/**
 * f_pint - Prints the value at the top of the stack.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void f_pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * f_pop - Removes the top element of the stack.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void f_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *stk = *stack;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->prev;
	if ((*stack) != NULL)
	{
		(*stack)->next = NULL;
	}
	free(stk);
}

/**
 * f_swap - Swaps the top two elements of the stack.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void f_swap(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	if (global.size < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		i = (*stack)->n;
		(*stack)->n = (*stack)->prev->n;
		(*stack)->prev->n = i;
	}
}
