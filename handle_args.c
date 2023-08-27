#include "monty.h"

/**
 * handle_args - handle args length
 * @arg_length: arguments length
 * Return: Returns exit status as failure or success
*/
int handle_args(int arg_length)
{
if (arg_length != 2)
{
return (error_usage());
}
return (EXIT_SUCCESS);
}
