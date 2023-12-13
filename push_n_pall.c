#include "monty.h"
/**
 * _atoi - string to int
 * @str: str
 * Return: the number
 */
int _atoi(char *str, char **parser)
{
int n;
if (_strlen(str) == 1 && str[0] == '0')
{
return (0);
}
n = atoi(str);
if (n == 0)
{
free_2d(parser);
free_stack();
exit(EXIT_FAILURE);
}
return (n);
}
/**
 * push - adds element to the stack
 * @hp: ptr to head of stack
 * @ln: line number of opcode
 * @parser: 3p
 */
void push(stack_t **hp, unsigned int ln, char **parser)
{
char *str;
int n;
stack_t *new_element;
if (parser_len(parser) != 2)
{
print_error("L");
str = _ratoi(ln);
print_error(str);
free(str);
print_error(": usage: push integer\n");
free_2d(parser);
free_stack();
exit(EXIT_FAILURE);
}
n = _atoi(parser[1], parser);
pue(parser[1], n, ln, parser);
new_element = (stack_t *)malloc(sizeof(stack_t));
if (new_element == NULL)
{
malloc_error(parser);
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
 * @parser: 3p
 * @ln: line number of opcode
 */
void pall(stack_t **hp, unsigned int ln, char **parser)
{
stack_t *current;
(void)ln;
(void)parser;
current = (*hp);
while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
}
}
