#include "monty.h"


char **op_toks = NULL;
int global_code = 0;
/**
 * main - entrypoint for the function
 * @argc: number of args
 * @argv: args
 * Return: EXIT_FAILURE OR EXIT_SUCCESS
*/


int main(int argc, char **argv)
{
int exit_int = EXIT_SUCCESS;
FILE *fd = NULL;
if (argc != 2)
return (handle_args(argc));
fd = fopen(argv[1], "r");
if (fd == NULL)
return (error_file_open(argv[1]));
exit_int = handle_run(fd);
exit_int = global_code;
fclose(fd);
return (exit_int);
}
