#include "monty.h"

/**
 * error_pop_ops - handle errors with pop ops
 * @line_number: line on which issue occured
 * Return: EXIT_FAILURE
*/

int error_pop_ops(unsigned int line_number)
{
fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
return (EXIT_FAILURE);
}

/**
 * error_pint_ops - handle errors with pop ops
 * @line_number: line on which issue occured
 * Return: EXIT_FAILURE
*/

int error_pint_ops(unsigned int line_number)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
return (EXIT_FAILURE);
}

/**
 * error_stack_length - handle errors with pop ops
 * @op: pointer to op_code
 * @line_number: line on which issue occured
 * Return: EXIT_FAILURE
*/

int error_stack_length(char *op, unsigned int line_number)
{
fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
return (EXIT_FAILURE);
}

/**
 * error_div_ops - handle errors with div ops
 * @line_number: line on which issue occured
 * Return: EXIT_FAILURE
*/
int error_div_ops(unsigned int line_number)
{
fprintf(stderr, "L%d: division by zero\n", line_number);
return (EXIT_FAILURE);
}

/**
 * error_unknown - returns unknown error
 * @line_number: line number
 * @op_code: operation code
 * Return: EXIT FAILURE OR EXIT SUCCESS
*/
int error_unknown(unsigned int line_number, char *op_code)
{
fprintf(stderr, "L%d: unknown instruction %s \n", line_number, op_code);
return (EXIT_FAILURE);
}
