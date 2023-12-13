#include "monty.h"
/**
 * malloc_error - error for malloc
 */
void malloc_error(void)
{
free_2d();
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
 */
void opcode_error(char *opcode, int ln)
{
free_stack();
printf("L%d: unknown instruction %s\n", ln, opcode);
free_2d();
exit(EXIT_FAILURE);
}

