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
if ((*hp)->n < 32 || (*hp)->n > 126)
{
print_error("L");
str = _ratoi(ln);
print_error(str);
free(str);
print_error(": can't pchar, value out of range\n");
free_2d(parser);
free_stack();
exit(EXIT_FAILURE);
}
printf("%c\n", (*hp)->n);
}
