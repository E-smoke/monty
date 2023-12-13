#include "monty.h"
/**
 * parser_len - number of strings in parser
 * @parser: 1p
 * Return: the number
 */
int parser_len(char **parser)
{
int len;
char **str;
len = 0;
str = parser;
while (str[len] != NULL)
{
++len;
}
return (len);
}
/**
 * _strcmp - compares if two strings are the same
 * @str1: 1p
 * @str2: 2p
 * Return: 1 if they are the same else 0
 */
int _strcmp(char *str1, char *str2)
{
int i;
if (_strlen(str1) != _strlen(str2))
{
return (0);
}
for (i = 0; i < _strlen(str1); ++i)
{
if (str2[i] != str1[i])
{
return (0);
}
}
return (1);
}
/**
 * filter - removes leading, trailling and multiple spaces
 * @str: the string to filteir
 * @parser: 2p
 * Return: filtered string in malloc form
 */
char *filter(char *str, char **parser)
{
int i;
int cnt;
char *filtered_line;
filtered_line = (char *)malloc(sizeof(char) * (filter_len(str, parser) + 1));
if (filtered_line == NULL)
{
malloc_error(parser);
}
i = 0;
cnt = 0;
while (str[i] != '\0')
{
if (str[i] == ' ')
{
if (i == 0)
{
++i;
continue;
}
if (str[i - 1] == ' ' && i != 0)
{
++i;
continue;
}
}
filtered_line[cnt] = str[i];
++i;
++cnt;
}
if (i == 0)
{
filtered_line[0] = '\0';
return (filtered_line);
}
if (filtered_line[cnt - 1] == ' ')
{
filtered_line[cnt - 1] = '\0';
}
else
{
filtered_line[cnt] = '\0';
}
return (filtered_line);
}
