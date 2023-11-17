#include "monty.h"

/* the pall and push opcodes Task 0*/

/**
 * p_all - Prints all values on the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 *
 */

void p_all(stack_t **stack, unsigned int line_number)
{
stack_t *current = *stack;

(void) line_number;
while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}

/**
 * push - Pushes an element onto the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */

void push(stack_t **stack, unsigned int line_number)
{
stack_t *new_node = malloc(sizeof(stack_t));

if (!new_node)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

if (*stack == NULL)
{
new_node->n = line_number;
new_node->next = NULL;
new_node->prev = NULL;
*stack = new_node;
}
else
{

new_node->n = line_number;
(*stack)->prev = new_node;
new_node->next = *stack;
new_node->prev = NULL;
*stack = new_node;
}
}

/* TASK 1 */

/**
 * p_int - Prints the value at the top of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 */

void p_int(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}

printf("%d\n", (*stack)->n);

}
