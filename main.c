#include "monty.h"
/**
 * f_open - Function for opens file
 * @argv: List of past arguments
 * Return: File open
 */
int f_open(char *argv)
{
	FILE *fp = NULL;

	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (fp);
}
/**
 * main - Reads a text file and prints in to the POSIX stdout
 * @argc: Check past arguments
 * @argv: List of past arguments
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	FILE *fp = NULL;
	size_t size = 0;
	char *delimiter = " \t\n", *str = NULL, **ptr = NULL;
	unsigned int line = 1;
	int arg = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = open(argv[1]);
	for ( ; getline(&str, &size, fp) != -1; line++)
	{
		ptr = malloc(sizeof(char *) * 2);
		if (ptr == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		ptr[0] = strtok(str, delimiter);
		ptr[1] = strtok(NULL, delimiter);
		if (ptr[1] != NULL)
		{
			arg = is_digit(ptr[1]);
			if (arg == -1)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line);
				exit(EXIT_FAILURE);
			}
			global = atoi(ptr[1]);
		}
		get_func(&stack, line, ptr[0]);
		free(ptr);
	}
	free(str);
	fclose(fp);
	return (0);
}
