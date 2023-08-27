#include "monty.h"

/**
 * handle_run - handles all operations
 * @fd: File descriptor
 * Return: Returns status
*/

int handle_run(FILE *fd)
{
stack_t *stack = NULL;
char line[1024];
size_t  exit_status = EXIT_SUCCESS;
unsigned int line_number = 0;
char *token;
int tokenCount;
void (*current_op)(stack_t**, unsigned int);
if (initialize_stack(&stack) == EXIT_FAILURE)
return (EXIT_FAILURE);
while (fgets(line, sizeof(line), fd) != NULL)
{
line_number++;
tokenCount = 0;
op_toks = (char **)malloc(2 * sizeof(char *));
token = strtok(line, " \t\n");
while (token != NULL && tokenCount < 3)
{
op_toks[tokenCount] = token;
tokenCount++;
token = strtok(NULL, " \t\n");
}
if (tokenCount > 0)
{
current_op = fetch_operational_func(op_toks[0]);
if (current_op == NULL)
{
free_stack(&stack);
return (error_unknown(line_number, op_toks[0]));
}
current_op(&stack, line_number);
if (global_code)
return (global_code);
}
else
{
free_op_toks();
continue;
}
}
return (exit_status);
}

