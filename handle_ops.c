#include "monty.h"


/**
 * fetch_operational_func - get the operational code
 * @op_code: The operational code
 * Return: A pointer to coressponding function
*/

void (*fetch_operational_func(char *op_code))(stack_t**, unsigned int)
{
instruction_t operational_funcs[] = {
{"push", handle_push},
{"pall", handle_pall},
{"pint", handle_pint},
{"pop", handle_pop},
{"swap", handle_swap},
{"nop", nop},
{"sub", handle_sub},
{"add", handle_add},
{"div", handle_div},
{"mod", handle_mod},
{"mul", handle_mul},
{NULL, NULL}
};
int index;
for (index = 0; operational_funcs[index].opcode; index++)
{
if (strcmp(op_code, operational_funcs[index].opcode) == 0)
return (operational_funcs[index].f);
}
return (NULL);
}


/**
 * free_op_toks - free the toks
*/
void free_op_toks(void)
{
size_t i = 0;
if (op_toks == NULL)
return;
for (i = 0; op_toks[i]; i++)
free(op_toks[i]);
}
