#include "monty.h"
void rotr(stack_t **hp, unsigned int ln, char **parser)
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
temp = *hp;
(last->prev)->next = NULL;
last->next = temp;
last->prev = NULL;
temp->prev = last;
}
}
