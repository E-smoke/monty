#include "monty.h"
/**
 * malloc_error - error for malloc
 * @parser: 1p
 */
void malloc_error(char **parser)
{
char *str;
free_2d(parser);
free_stack();
str = "Error: malloc failed\n";
print_error(str);
exit(EXIT_FAILURE);
}
/**
 * file_error - error for file opening
 * @filename: name of the file
 */
void file_error(char *filename)
{
char *str = "Error: Can't open file ";
print_error(str);
print_error(filename);
print_error("\n");
exit(EXIT_FAILURE);
}
/**
 * usage_error - error for monty usage
 * @n: takes argc
 */
void usage_error(int n)
{
if (n != 2)
{
print_error("USAGE: monty file\n");
exit(EXIT_FAILURE);
}
}
/**
 * opcode_error - error wrong opcode
 * @opcode: takes in opcode
 * @ln: line number of the opcode
 * @parser: 3p
 */
void opcode_error(char *opcode, int ln, char **parser)
{
char *str;
print_error("L");
str = _ratoi(ln);
print_error(str);
free(str);
print_error(": unknown instruction ");
print_error(opcode);
print_error("\n");
free_2d(parser);
free_stack();
exit(EXIT_FAILURE);
}




void pue(char *str,int n, int ln, char **parser)
{
if (n == 0 && _strlen(str) != 1 && str[0] != '0')
{
char *str;
print_error("L");
str = _ratoi(ln);
print_error(str);
free(str);
print_error(": usage: push integer\n");
free_2d(parser);
free_stack();
exit(EXIT_FAILURE);
}
}
