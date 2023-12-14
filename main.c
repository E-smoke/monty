#include "monty.h"
stack_t *head = NULL;


int main(int argc, char *argv[])
{
int i, ln, ind, fd;
char buff[BS];
char *buff_ptr;
char **parser = NULL;
instruction_t3 functs[] = 
{
{"swap", swap},
{"pop", pop},
{"push", push},
{"pint", pint},
{"pall", pall},
{NULL, NULL},
};
usage_error(argc);
fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
file_error(argv[1]);
}
ln = 0;
ind = 2;
while (ind == 2)
{
buff_ptr = buff;
ind = read_line(fd, &buff_ptr);
++ln;
if (ind == -1)
{
free_stack();
exit(EXIT_FAILURE);
}
buff_ptr = filter(buff_ptr, parser);
parser = fparser(buff_ptr, parser);
free(buff_ptr);
if (parser[0] == NULL)
{
free_2d(parser);
continue;
}
i = 0;
while (functs[i].f != NULL)
{
if (_strcmp(functs[i].opcode, parser[0]) == 1)
{
(functs[i].f)(&head, ln, parser);
free_2d(parser);
break;
}
++i;
}
if (functs[i].f == NULL)
{
opcode_error(parser[0], ln, parser);
}
}
free_stack();
close(fd);
return (0);
}
