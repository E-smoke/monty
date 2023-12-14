#include "monty.h"
void mod(stack_t **hp, unsigned int ln, char **parser)
{
char *str;
stack_t *temp;
if ((*hp) == NULL || (*hp)->next == NULL)
{
print_error("L");
str = _ratoi(ln);
print_error(str);
free(str);
print_error(": can't mod, stack too short\n");
free_2d(parser);
free_stack();
exit(EXIT_FAILURE);
}
if ((*hp)->n == 0)
{
print_error("L");
str = _ratoi(ln);
print_error(str);
free(str);
print_error(": division by zero\n");
free_2d(parser);
free_stack();
exit(EXIT_FAILURE);
}
temp = (*hp);
(*hp) = (*hp)->next;
(*hp)->n = (*hp)->n % temp->n;
free(temp);
}
