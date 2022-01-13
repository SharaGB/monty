#include "monty.h"
/**
 * _strdup - Contains a copy of the string
 * @str: Check string
 * Return: A pointer
 */
char *_strdup(char *str)
{
	int len = 0;
	char *ptr;
	char *dub;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[len] != '\0')
	{
		len++;
	}
	ptr = malloc(sizeof(char) * len + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	dub = ptr;
	while (*str)
	{
		*dub = *str;
		dub++;
		str++;
	}
	*dub = '\0';
	return (ptr);
}
/**
 * is_digit - Checks for a digit
 * @digit: Check number
 * Return: The check number
 */
int is_digit(char *digit)
{
	int i = 0;

	if (digit[i] == '-')
	{
		i++;
	}
	while (digit[i])
	{
		if (digit[i] >= '0' && digit[i] <= '9')
		{
			return (0);
		}
		if (isdigit(digit[i]) == 0)
		{
			return (1);
		}
		i++;
	}
	return (1);
}


/**
 * free_stack - Frees the stack
 * @head: The stack
 */
void free_stack(stack_t *head)
{
	stack_t *tmp = head;

	while (tmp != NULL)
	{
		tmp = tmp->next;
		free(head);
		head = tmp;
	}
}

/**
 * _strlen - The length of a string
 * @s: Check the string
 *
 * Return: Always 0
 */
int _strlen(stack_t *s)
{
	int len = 0;

	while (s)
	{
		s = s->next;
		len++;
	}
	return (len);
}