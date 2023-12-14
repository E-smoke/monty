#ifndef MAIN_INCLUDED
#define MAIN_INCLUDED
#define BS 1024
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;






/**
 * struct instruction_s3 - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s3
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number, char **parser);
} instruction_t3;





extern stack_t *head;



int _strlen(char *str);
int filter_len(char *str);
char *filter(char *str, char **parser);
char *token(char *fstr);
int word_count(char *str);
char **fparser(char *fstr,char **parser);
int parser_len(char **parser);
int _atoi(char *str, char **parser);
void push(stack_t **hp, unsigned int ln, char **parser);
void pall(stack_t **hp, unsigned int ln, char **parser);
void malloc_error(char **parser);
void file_error(char *filename);
void usage_error(int n);
void opcode_error(char *opcode, int ln, char **parser);
int read_line(unsigned int fd, char **buff);
void free_2d(char **parser);
void free_stack(void);
int _strcmp(char *str1, char *str2);
char *_ratoi(int number);
void pue(char *str, int n, int ln, char **parser);
void print_error(char *str);
void pint(stack_t **hp, unsigned int ln, char **parser);
void pop(stack_t **hp, unsigned int ln, char **parser);
void swap(stack_t **hp, unsigned int ln, char **parser);
void add(stack_t **hp, unsigned int ln, char **parser);
void nop(stack_t **hp, unsigned int ln, char **parser);
void sub(stack_t **hp, unsigned int ln, char **parser);
void mult(stack_t **hp, unsigned int ln, char **parser);
void division(stack_t **hp, unsigned int ln, char **parser);
#endif
