#include "monty.h"

/**
 * error_usage - prints errors with usage of monty
 * Return: EXIT_FAILURE status
*/

int error_usage(void)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}

/**
 * error_malloc - Handle malloc errors
 * Return: EXIT_FAILURE status
*/
int error_malloc(void)
{
fprintf(stderr, "Error: malloc failed\n");
return (EXIT_FAILURE);
}
/**
 * error_file_open - handle errors with opening file
 * @file_name: pointer to filename
 * Return: EXIT_FAILURE status
*/
int error_file_open(char *file_name)
{
fprintf(stderr, "Error: Can't open file %s\n", file_name);
return (EXIT_FAILURE);
}

/**
 * error_operation - handles error with operations
 * @op: pointer to operation code
 * @line_number: Line on which error occured
 * Return: EXIT FAILURE
*/

int error_operation(char *op, unsigned int line_number)
{
fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op);
return (EXIT_FAILURE);
}

/**
 * error_with_push_op - handles error with push operation
 * @line_number: Line on which the error occured
 * Return: Returns EXIT_FAILURE
*/

int error_with_push_op(unsigned int line_number)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
return (EXIT_FAILURE);
}
