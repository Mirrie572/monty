#include "monty.h"
/**
 * add -  the functon Adds the top two elements
 * of the stack.
 * @stack: points to the stack.
 * @line_number: The current line number.
 *
 * return: void
 */

void add(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

(*stack)->next->n += (*stack)->n;
pop(stack, line_number);
}

/**
 * p_str - Print the ASCII representation of the elements on the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number (unused).
 *
 * Description:
 * p_str prints the ASCII representation of the elements on the stack until
 * it encounters a non-printable character (outside the ASCII range 1 to 127)
 * or the stack is empty. Each character is printed without a newline.
 */

void p_str(stack_t **stack, unsigned int line_number)
{

stack_t *current_node;

current_node = *stack;

(void)line_number;
/* Unused parameter */

/* Traverse the stack and print ASCII characters */
while (current_node != NULL)
{
/* Break if the character is non-printable or the stack is empty */
if (current_node->n > 127 || current_node->n <= 0)
{
break;
}

/* Print the ASCII character */
printf("%c", current_node->n);

/* Move to the next node in the stack */
current_node = current_node->next;
}

/* Print a newline character to end the output */
printf("\n");
}
