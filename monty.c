#include "monty.h"
/**
 * fpush - Pushes an element to the stack.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void fpush(stack_t **stack, unsigned int line_number)
{
	char *arg = NULL;
	int i = 0;

	arg = strtok(NULL, DELIMITER);
	if (arg == NULL || check_for_digit(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = atoi(arg);
	if (!add_node(stack, i))
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	global.size++;
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
		tmp = tmp->next;
	}
}

/**
 * fpint - Prints the value at the top of the stack.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void fpint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * fpop - Removes the top element of the stack.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void fpop(stack_t **stack, unsigned int line_number)
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
 * fswap - Swaps the top two elements of the stack.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void fswap(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *tmp = *stack;

	if (!*stack || !(*stack)->prev)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		tmp = *stack;
		tmp = (*stack)->next;
		tmp->prev = NULL;
		(*stack)->next = tmp->next;
		if (tmp->next != NULL)
			tmp->next->prev = (*stack);
		tmp->next = (*stack);
		(*stack)->prev = tmp;
		*stack = tmp;
	}
}
