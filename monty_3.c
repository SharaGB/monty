#include "monty.h"
/**
 * f_mod - Division of the second top element by the top element.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void f_mod(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	if (global.size < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = (*stack)->n;
	f_pop(stack, line_number);
	if (i == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->n %= i;
}

/**
 * f_rotl - Rotates the stack to the top.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void f_rotl(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *tmp = *stack;

	if (*stack)
	{
		i = tmp->n;
		f_pop(stack, line_number);
		add_dnodeint_end(stack, i);
	}
}

/**
 * f_rotr - Rotates the stack to the bottom.
 * @stack: Header of the list(stack)
 * @line_number: Line data
 */
void f_rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp = *stack;

	if ((*stack)->next)
	{
		while (tmp->next->next)
		{
			tmp = tmp->next;
		}

		(*stack)->prev = tmp->next;
		(tmp->next)->prev = NULL;
		(tmp->next)->next = *stack;
		tmp->next = NULL;
		*stack = (*stack)->prev;
	}
}

/**
 * free_matrix - Free the array
 *@head: Free the array
 */
void free_matrix(char **head)
{
	int position = 0;

	while (head[position])
	{
		free(head[position]);
		position++;
	}
	free(head);
}
