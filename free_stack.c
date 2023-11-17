#include "monty.h"
/**
 * fstack - frees the stack.
 * @s: the head stack
 *
 * return: nothing
 */

void fstack(stack_t **s)
{
stack_t *tmp;

tmp = *s;
while (*s)
{
tmp = (*s)->next;
free(*s);
*s = tmp;
}
}
