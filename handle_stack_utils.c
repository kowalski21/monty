#include "monty.h"


/**
 * free_stack - Frees the stack to avoid memory issues
 * @stack: pointer to stack struct
*/

void free_stack(stack_t **stack)
{
stack_t *tmp = *stack;
while (*stack)
{
tmp = (*stack)->next;
free(*stack);
*stack = tmp;
}
}
/**
 * initialize_stack - initializes the stack
 * @stack: pointer to stack struct
 * Return: EXIT_FAILURE or EXIT_SUCCESS
*/
int initialize_stack(stack_t **stack)
{
stack_t *s;
s = malloc(sizeof(stack_t));
if (s == NULL)
return (error_malloc());
s->n = STACK;
s->prev = NULL;
s->next = NULL;
*stack = s;
return (EXIT_SUCCESS);
}

/**
 * check_operation_mode - Checks the operation mode
 * @stack: stack struct
 * Return: returns EXIT_FAILURE or EXIT_SUCCESS
*/

int check_operation_mode(stack_t *stack)
{
if (stack->n == STACK)
return (STACK);
else if (stack->n == QUEUE)
return (QUEUE);
return (4);
}
