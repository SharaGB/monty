#include "monty.h"
/**
 * is_digit - Checks for a digit
 * @digit: Check number
 * Return: Always 0
 */
int is_digit(char *digit)
{
	int i;

	for (i = 0; digit[i]; i++)
	{
		if (digit[i] == '-' && i == 0)
		{
			continue;
		}
		if (isdigit(digit[i]) == 0)
		{
			return (1);
		}
	}
	return (0);
}

/**
 * add_node - Add a new node.
 * @stack: Header of the list(stack)
 * @n: Value new node
 * Return: pointer to the new node, or NULL on failure
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		return (NULL);
	}
	if (!stack)
	{
		return (NULL);
	}
	new_node->n = n;
	if (!*stack)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	else
	{
		(*stack)->next = new_node;
		new_node->prev = *stack;
	}
	if (global.data == STACK || global.size == 0)
	{
		*stack = new_node;
	}
	return (new_node);
}

/**
 * free_stack - Frees the stack
 * @fre: Exit check
 * @args: Line arguments
 */
void free_stack(int fre, void *args)
{
	stack_t **stack;
	stack_t *next;

	(void)fre;

	stack = (stack_t **)args;
	if (*stack)
	{
		(*stack)->prev->next = NULL;
		(*stack)->prev = NULL;
	}
	while (*stack != NULL)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
	global.size = 0;
}

/**
 * frees - Frees the array
 * @fre: Exit check
 * @args: Line arguments
 */
void frees(int fre, void *args)
{
	char **ptr = args;

	(void)fre;
	if (*ptr != NULL)
	{
		free(*ptr);
	}
}
