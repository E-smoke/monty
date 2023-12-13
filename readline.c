#include "monty.h"
/**
 * read_line - read a line in a file
 * @fd: file descriptor
 * @buff: ptr to the buffer
 * Return: -1 on failure, 0 on reaching EOF, and 2 if a line is read to '\n'
 */
int read_line(unsigned int fd, char **buff)
{
static char ch = '\n';
int i;
static int ind;
if (ch == '\n')
{
ind = read(fd, &ch, 1);
}
i = 0;
while (ch != '\n' && i != BS)
{
if (ind == 0)
{
(*buff)[i] = '\0';
return (0);
}
if (ind < 0)
{
(*buff)[0] = '\0';
return (-1);
}
(*buff)[i] = ch;
++i;
ind = read(fd, &ch, 1);
}
(*buff)[i] = '\0';
if (ch == '\n')
{
if (ind == 0)
{
return (0);
}
return (2);
}
return (ind);
}
