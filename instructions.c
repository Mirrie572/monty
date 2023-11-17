#include "monty.h"

instruction_t instruction[] = {
{"push", push},
{"pall", p_all},
{"pint", p_int},
{"swap", swap},
{"pop", pop},
{"add", add},
{"nop", nop},
{"sub", sub},
{"div", f_div},
{"mul", mul},
{"#", nop},
{"pchar", p_char},
{"rotl", rotl},
{"rotr", rotr},
{"NULL", NULL}
};
