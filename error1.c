#include "monty.h"
void print_error(char *str)
{
write(STDERR_FILENO, str, _strlen(str));
}
