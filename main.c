#include "monty.h"
/**
 * main - Reads a text file and prints in to the POSIX stdout
 * @argc: Check past arguments
 * @argv: List of past arguments
 * Return: Always 0
 */
int main(int argc __attribute__((unused)), char **argv)
{
	char str[60];
	FILE *fp = NULL;
	char **tokens = NULL;
	char *tokenline = NULL;
	int line = 1;
	stack_t *pila = NULL;

	fp = fopen(argv[1], "r"); /* Abrir el archivo para su lectura */
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(str, 1024, fp) != NULL)
	{
		tokens = malloc(sizeof(char *) * 1024);
		if (!tokens)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		tokenline = strtok(str, DELIMITER); /*Lo almacena dentro de tokenlinen*/
		if (tokenline != NULL)
		{
			get_func(tokenline, &pila, tokenline[5] - '0');
		}
		line++;
	}
	fclose(fp);
	return (0);
}
