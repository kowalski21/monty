
#include "monty.h"

/**
 * handle_push - push op for monty app
 * @stack: pointer to stack struct
 * @line_number: current line number;
*/
void handle_push(stack_t **stack, unsigned int line_number)
{
stack_t *stack_tmp, *new;
int i;
new = malloc(sizeof(stack_t));
if (new == NULL)
{
set_global(1);
error_malloc();
return;
}
if (op_toks[1] == NULL)
{
set_global(1);
error_with_push_op(line_number);
return;
}

for (i = 0; op_toks[1][i]; i++)
{
if (op_toks[1][i] == '-' && i == 0)
continue;
if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
{
set_global(1);
error_with_push_op(line_number);
return;
}
}
new->n = atoi(op_toks[1]);
stack_tmp = (*stack)->next;
new->prev = *stack;
new->next = stack_tmp;
if (stack_tmp)
stack_tmp->prev = new;
(*stack)->next = new;
}

/**
 * handle_pall - handle printing stack
 * @stack: pointer to stack struct
 * @line_number: current line number;
*/

void handle_pall(stack_t **stack, unsigned int line_number)
{
stack_t *stack_tmp = (*stack)->next;
while (stack_tmp)
{
printf("%d\n", stack_tmp->n);
stack_tmp = stack_tmp->next;
}
(void)line_number;
}


/**
 * handle_pint - Prints the number on top of the stack
 * @stack: pointer to struct stack linked list
 * @line_number: line number in file
*/

void handle_pint(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL)
{
set_global(1);
error_pint_ops(line_number);
return;
}
printf("%d\n", (*stack)->next->n);
}


/**
 * handle_pop - Removes value from the linked list
 * @stack: pointer to stack_t linked_list
 * @line_number: line number
*/

void handle_pop(stack_t **stack, unsigned int line_number)
{
stack_t *next_stack = NULL;
if ((*stack)->next == NULL)
{
set_global(1);
error_pop_ops(line_number);
return;
}
next_stack = (*stack)->next->next;
free((*stack)->next);
if (next_stack)
next_stack->prev = *stack;
(*stack)->next = next_stack;
}


/**
 * handle_swap - Swaps values
 * @stack: A pointer to linked_list
 * @line_number: current line number
 */
void handle_swap(stack_t **stack, unsigned int line_number)
{
stack_t *tmp;

if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_global(1);
error_stack_length("swap", line_number);
return;
}
tmp = (*stack)->next->next;
(*stack)->next->next = tmp->next;
(*stack)->next->prev = tmp;
if (tmp->next)
tmp->next->prev = (*stack)->next;
tmp->next = (*stack)->next;
tmp->prev = *stack;
(*stack)->next = tmp;
}
