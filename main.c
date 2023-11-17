#include "monty.h"

/**
 * main - The entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, or an exit code on failure.
 */

int main(int argc, char **argv);

int main(int argc, char **argv)
{
char *line = NULL;
size_t len = 0;
ssize_t line_len;
FILE *stream;
unsigned int line_number = 1;
stack_t *stack = NULL;

if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
stream = fopen(argv[1], "r");

if (stream == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}
while ((line_len = getline(&line, &len, stream)) != -1)
{
char *line_cpy = strdup(line);
char *token = strtok(line_cpy, " \n\t\r");

if (!line_cpy)
{
fprintf(stderr, "Error: malloc failed\n");
fclose(stream);
fstack(&stack);
exit(EXIT_FAILURE);
}
if (line_len > 1 && token != NULL)

input_process(line, &line_number, &stack, stream);

line_number++;
free(line_cpy);
}
fclose(stream);
free(line);
fstack(&stack);
return (0);
}
