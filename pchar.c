#include "monty.h"
void pchar(stack_t **hp, unsigned int ln, char **parser)
{
char *str;
if ((*hp) == NULL)
{
print_error("L");
str = _ratoi(ln);
print_error(str);
free(str);
print_error(": can't pchar, stack empty\n");
free_2d(parser);
free_stack();
exit(EXIT_FAILURE);
}
if ((*hp)->n < 0 || (*hp)->n > 127)
{
print_error("L");
str = _ratoi(ln);
print_error(str);
free(str);
print_error(": can't pchar, value out of range");
free_2d(parser);
free_stack();
exit(EXIT_FAILURE);
}
printf("%c\n", (*hp)->n);
}
