#include "monty.h"
/**
 * free_2d - frees the parser global var
 */
void free_2d(void)
{
int i;
i = 0;
while (parser[i] != NULL)
{
free(parser[i]);
++i;
}
free(parser);
}



/**
 * free_stack - free the stack
 */
void free_stack(void)
{
stack_t *current;
current = head;
if (current == NULL)
{
return;
}
while (current->next != NULL)
{
current = current->next;
free(current->prev);
}
free(current);
}
