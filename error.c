#include "monty.h"
/**
 * malloc_error - error for malloc
 * @parser: 1p
 */
void malloc_error(char **parser)
{
free_2d(parser);
free_stack();
printf("Error: malloc failed\n");
exit(EXIT_FAILURE);
}
/**
 * file_error - error for file opening
 * @filename: name of the file
 */
void file_error(char *filename)
{
printf("Error: Can't open file %s\n", filename);
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
printf("USAGE: monty file\n");
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
free_stack();
printf("L%d: unknown instruction %s\n", ln, opcode);
free_2d(parser);
exit(EXIT_FAILURE);
}



void naming_error(char *name)
{
int len;
len = _strlen(name);
if (!(name[len - 1] == 'm' && name[len - 2] == '.'))
{
exit(EXIT_FAILURE);
}
}
