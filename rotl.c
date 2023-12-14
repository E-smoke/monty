#include "monty.h"
void rotl(stack_t **hp, unsigned int ln, char **parser)
{
stack_t *last;
stack_t *temp;
(void)ln;
(void)parser;
last = (*hp);
if (last == NULL)
{
return;
}
while (last->next != NULL)
{
last = last->next;
}
if (last != (*hp))
{
temp = (*hp);
(*hp) = (*hp)->next;
(*hp)->prev = NULL;
temp->next = NULL;
temp->prev = last;
last->next = temp;
}
}
