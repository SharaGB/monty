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
 * new_node - Add a new node.
 * @stack: Header of the list(stack)
 * @n: Value new node
 * Return: pointer to the new node, or NULL on failure
 */
stack_t *new_node(stack_t **stack, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		free(new_node);
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
	*stack = new_node;
	return (new_node);
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

/**
 * free_stack - Function that frees a list
 * @stack: Free stack
 */
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

/**
 * add_dnodeint_end - Adds a new node at the end of a list
 * @head: Head of the list
 * @n: Value to add to the new node
 * Return: Address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *tmp = NULL;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		free(new_node);
		return (NULL);
	}
	if (!head)
	{
		return (NULL);
	}
	new_node->n = n;
	new_node->next = NULL;
	if (!*head)
	{
		*head = new_node;
		(*head)->prev = NULL;
		return (new_node);
	}
	tmp = *head;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new_node;
	new_node->prev = tmp;
	tmp = new_node;

	return (new_node);
}
