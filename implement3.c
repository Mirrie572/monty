#include "monty.h"

/* new tasks  */

/**
 * p_char - Print the ASCII character
 * representation of the top element.
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 *
 * return: void
 */

void p_char(stack_t **stack, unsigned int line_number)
{

if (!(*stack))
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
exit(EXIT_FAILURE);
}

if ((*stack)->n < 33 || (*stack)->n > 126)
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
exit(EXIT_FAILURE);
}

printf("%c\n", (*stack)->n);

}

/**
 * rotl - Rotates the stack to the top.
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 *
 * Return: void
 */

void rotl(stack_t **stack, unsigned int line_number)
{
(void)line_number;
/* not used hence */

/* Check if the stack and the next node exist */
if (*stack && (*stack)->next)
{
stack_t *top = *stack;
stack_t *second = top->next;
stack_t *last = *stack;

/* Traverse the stack to find the last node */
while (last->next)
last = last->next;

/* Adjust the pointers to perform the rotation */
top->next = last->next;
top->prev = last;
last->next = top;
second->prev = NULL;
*stack = second;
/* Update the stack pointer to the new top */
}
}

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 *
 * return: void
 */

void rotr(stack_t **stack, unsigned int line_number)
{

stack_t *tmp_node;
stack_t *last_node;
(void)line_number;

if (*stack == NULL || (*stack)->next == NULL)
return;

last_node = *stack;
while (last_node->next != NULL)
last_node = last_node->next;

tmp_node = last_node->prev;
tmp_node->next = NULL;
last_node->prev = NULL;
last_node->next = *stack;
(*stack)->prev = last_node;
*stack = last_node;
}

/**
 * mul - Multiplies the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: The current line number.
 *
 * Return: void.
 */
void mul(stack_t **stack, unsigned int line_number)
{

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

/* Multiply the top two elements of the stack */

(*stack)->next->n *= (*stack)->n;

pop(stack, line_number);
}

/**
 * f_div -  function that Divide the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 *
 * return: void
 */


void f_div(stack_t **stack, unsigned int line_number)
{
if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
exit(EXIT_FAILURE);
}
if ((*stack)->n == 0)
{
fprintf(stderr, "L%d: division by zero\n", line_number);
exit(EXIT_FAILURE);
}
(*stack)->next->n = (*stack)->next->n / (*stack)->n;
pop(stack, line_number);
}
