#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define STACK 0
#define QUEUE 1

extern char **op_toks;
extern int global_code;


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

int handle_args(int arg_length);
int handle_run(FILE *fd);


void free_op_toks(void);


void set_global(int error_code);

void free_stack(stack_t **stack);
int initialize_stack(stack_t **stack);
int check_operation_mode(stack_t *stack);

int error_unknown(unsigned int line_number,char *op_code);
int error_usage(void);
int error_malloc(void);
int error_file_open(char *file_name);
int error_operation(char *op, unsigned int line_number);
int error_with_push_op(unsigned int line_number);
int error_pop_ops(unsigned int line_number);
int error_pop_ops(unsigned int line_number);
int error_pint_ops(unsigned int line_number);
int error_stack_length(char *op, unsigned int line_number);
int error_div_ops(unsigned int line_number);



void handle_push(stack_t **stack, unsigned int line_number);
void handle_pall(stack_t **stack, unsigned int line_number);
void handle_pint(stack_t **stack, unsigned int line_number);
void handle_pop(stack_t **stack, unsigned int line_number);
void handle_swap(stack_t **stack, unsigned int line_number);
void handle_add(stack_t **stack, unsigned int line_number);
void handle_sub(stack_t **stack, unsigned int line_number);
void handle_mul(stack_t **stack, unsigned int line_number);
void handle_div(stack_t **stack, unsigned int line_number);
void handle_mod(stack_t **stack, unsigned int line_number);
void nop(stack_t  __attribute__((__unused__)) **stack, unsigned int ln);
void (*fetch_operational_func(char *op_code))(stack_t**, unsigned int);
#endif /* __MONTY_H__ */
