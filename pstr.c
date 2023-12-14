#include "monty.h"
void pstr(stack_t **hp, unsigned int ln, char **parser)
{
stack_t *current;
(void)ln;
(void)parser;
current = (*hp);
while (current != NULL)
{
if (current->n < 1 || current->n > 127)
{
break;
}
printf("%c", current->n);
current = current->next;
}
printf("\n");
}
