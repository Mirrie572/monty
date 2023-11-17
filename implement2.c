#include "monty.h"

/* tasks 2 to 6 */

/**
 * pop - This function Removes the top element of the stack.
 * @stack: pointS to the stack.
 * @line_number: current line number.
 *
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
stack_t *temp_node;

/*if the stack is empty */
if (*stack == NULL)
{
fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
exit(EXIT_FAILURE);
}

/* Temporary pointer to hold the address of the top node */
temp_node = *stack;

*stack = temp_node->next;

if (*stack != NULL)
(*stack)->prev = NULL;

free(temp_node);
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 *
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
stack_t *temp_node;
/* Check stack conditions and swap nodes */

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

temp_node = *stack;

*stack = (*stack)->next;

temp_node->next = (*stack)->next;

temp_node->prev = *stack;

(*stack)->next = temp_node;

if (temp_node->next != NULL)
{
temp_node->next->prev = temp_node;
}

}

/**
 * nop - Does nothing.
 * @stack: points at the top node of the stack.
 * @line_number: an int representing the line number of of the opcode.
 *
 * return: void
 */

void nop(stack_t **stack, unsigned int line_number)
{
(void)stack;
(void)line_number;
}

/**
 * sub - Subtracts the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number.
 *
 * return: void
 * This function performs the subtraction
 * operation on the top two elements of the stack.
 */

void sub(stack_t **stack, unsigned int line_number)
{

if (*stack == NULL || (*stack)->next == NULL)
{
fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
exit(EXIT_FAILURE);
}

/* Perform the subtraction operation on the top two elements */
(*stack)->next->n = ((*stack)->next->n - (*stack)->n);

/* Remove the top element from the stack */
pop(stack, line_number);
}

