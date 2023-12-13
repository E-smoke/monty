#include "monty.h"
stack_t *head = NULL;
char **parser = NULL;


int main(int argc, char *argv[])
{
int i, ln, ind, fd;
char buff[BS];
char *buff_ptr;
instruction_t functs[] = 
{
{"push", push},
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
buff_ptr = filter(buff_ptr);
parser = fparser(buff_ptr);
free(buff_ptr);
if (parser[0] == NULL)
{
free_2d();
continue;
}
i = 0;
while (functs[i].f != NULL)
{
if (_strcmp(functs[i].opcode, parser[0]) == 1)
{
(functs[i].f)(&head, ln);
free_2d();
break;
}
++i;
}
if (functs[i].f == NULL)
{
opcode_error(parser[0], ln);
}
}
free_stack();
return (0);
}
