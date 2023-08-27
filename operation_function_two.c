#include "monty.h"

/**
 * nop  - handle no operation
 * @stack: pointer to stack
 * @ln: line number
*/

void nop(stack_t  __attribute__((__unused__)) **stack, unsigned int ln)
{
int tmp_line = ln;
tmp_line += ln;

}


/**
 * handle_add - adds top two values in linked list
 * @stack: stack
 * @line_number: line number current
*/

void handle_add(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_global(1);
error_stack_length("add", line_number);
return;
}
(*stack)->next->next->n += (*stack)->next->n;
handle_pop(stack, line_number);
}


/**
 * handle_sub - subtracts top two values in linked list
 * @stack: stack
 * @line_number: line number current
*/

void handle_sub(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_global(1);
error_stack_length("sub", line_number);
return;
}
(*stack)->next->next->n -= (*stack)->next->n;
handle_pop(stack, line_number);
}


/**
 * handle_mul - subtracts top two values in linked list
 * @stack: stack
 * @line_number: line number current
*/

void handle_mul(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_global(1);
error_stack_length("mul", line_number);
return;
}
(*stack)->next->next->n *= (*stack)->next->n;
handle_pop(stack, line_number);
}



/**
 * handle_div - subtracts top two values in linked list
 * @stack: stack
 * @line_number: line number current
*/

void handle_div(stack_t **stack, unsigned int line_number)
{
if ((*stack)->next == NULL || (*stack)->next->next == NULL)
{
set_global(1);
error_stack_length("div", line_number);
return;
}
if ((*stack)->next->n == 0)
{
set_global(1);
error_div_ops(line_number);
return;
}

(*stack)->next->next->n /= (*stack)->next->n;
handle_pop(stack, line_number);
}

