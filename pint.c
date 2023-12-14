#include "monty.h"
void pint(stack_t **hp, unsigned int ln, char **parser)
{
char *str;
if ((*hp) == NULL)
{
print_error("L");
str = _ratoi(ln);
print_error(str);
free(str);
print_error(": can't pint, stack empty\n");
free_2d(parser);
free_stack();
exit(EXIT_FAILURE);
}
printf("%d\n", (*hp)->n);
}
