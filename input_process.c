#include "monty.h"

/**
 * input_process - Processes a line of input.
 *
 * @line: The line to process.
 * @current: A pointer to the current line number.
 * @stack: A pointer to the current line number.
 * @file: A pointer to the current line number.
 */

void input_process(char *line, unsigned int *current,
		stack_t **stack, FILE *file)
{
char *tkn;
char *arg;
char *cpy_line = strdup(line);

if (!cpy_line)
{
fprintf(stderr, "Error: malloc failed\n");

fclose(file);

fstack(stack);

exit(EXIT_FAILURE);
}
tkn = strtok(cpy_line, " \n\t\r");
arg = strtok(NULL, " \n\t\r");

_execute(tkn, arg, current, stack, file);

free(cpy_line);

}
