#include "monty.h"


/**
 * handle_mod - modulus
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: line number
 */
void handle_mod(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_global(1);
error_stack_length("mod", line_number);
return;
}
if ((*stack)->next->n == 0)
{
set_global(1);
error_div_ops(line_number);
return;
}
(*stack)->next->next->n %= (*stack)->next->n;
handle_pop(stack, line_number);
}
