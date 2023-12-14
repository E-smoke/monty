#include "monty.h"
void pop(stack_t **hp, unsigned int ln, char **parser)
{
char *str;
stack_t *pope;
if ((*hp) == NULL)
{
print_error("L");
str = _ratoi(ln);
print_error(str);
free(str);
print_error(": can't pop an empty stack\n");
free_2d(parser);
free_stack();
exit(EXIT_FAILURE);
}
pope = (*hp);
(*hp) = (*hp)->next;
if ((*hp) != NULL)
{
(*hp)->prev = NULL;
}
free(pope);
}
