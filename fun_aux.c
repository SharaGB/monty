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
