#include "monty.h"
/**
 * _atoi - string to int
 * @str: str
 * Return: the number
 */
int _atoi(char *str)
{
int n;
if (_strlen(str) == 1 && str[0] == '0')
{
return (0);
}
n = atoi(str);
if (n == 0)
{
free_2d();
free_stack();
exit(EXIT_FAILURE);
}
return (n);
}
/**
 * push - adds element to the stack
 * @hp: ptr to head of stack
 * @ln: line number of opcode
 */
void push(stack_t **hp, unsigned int ln)
{
int n;
stack_t *new_element;
if (parser_len() != 2)
{
opcode_error(parser[0], ln);
}
n = _atoi(parser[1]);
new_element = (stack_t *)malloc(sizeof(stack_t));
if (new_element == NULL)
{
malloc_error();
}
if ((*hp) == NULL)
{
(*hp) = new_element;
new_element->next = NULL;
new_element->prev = NULL;
new_element->n = n;
}
else
{
new_element->next = (*hp);
new_element->prev = NULL;
new_element->n = n;
(*hp)->prev = new_element;
(*hp) = new_element;
}
}
/**
 * pall - prints all the elements in the stack
 * @hp: ptr to head
 * @ln: line number of opcode
 */
void pall(stack_t **hp, unsigned int ln)
{
stack_t *current;
if (parser_len() != 1)
{
opcode_error(parser[0], ln);
}
current = (*hp);
while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}
