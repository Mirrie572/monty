#include "monty.h"

/**
 * _execute - this function executes a specific instruction
 * and handles errors
 * @tkn: instruction token.
 * @arg: These are the argument associated with the instruction.
 * @current: The current line number.
 * @stack: points to the stack.
 * @file: points to the stack.
 *
 * Return: instructions results or error message
 */

void _execute(char *tkn, char *arg,
unsigned int *current, stack_t **stack, FILE *file)
{
int id = 0;
int idx = 0;

if (tkn[0] == '#')
{
id = 1;
nop(stack, *current);
}
while (instruction[idx].opcode != NULL)
{
if (strcmp(tkn, instruction[idx].opcode) == 0)
{
if (strcmp(tkn, "push") == 0)
{
if (arg == NULL || !strckr(arg))
{
fprintf(stderr, "L%d: usage: push integer\n", *current);
fclose(file);
fstack(stack);
exit(EXIT_FAILURE);
}
instruction[idx].f(stack, atoi(arg));
}
else
instruction[idx].f(stack, *current);
id = 1;
break;
}
idx++;
}
if (!id)
{
fprintf(stderr, "L%d: unknown instruction %s\n", *current, tkn);
fstack(stack);
fclose(file);
exit(EXIT_FAILURE);
}
}
