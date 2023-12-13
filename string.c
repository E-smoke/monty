#include "monty.h"
/**
 * _strlen - returns string len
 * @str: str
 * Return: int
 */
int _strlen(char *str)
{
int i;
i = 0;
while (str[i] != '\0')
{
++i;
}
return (i);
}
/**
 * filter_len: returns the length as if it were filtered
 * @str: str
 * Return: int
 */
int filter_len(char *str)
{
int i;
int cnt;
cnt = 0;
i = 0;
while (str[i] != '\0')
{
if (str[i] == ' ')
{
if (i == 0)
{
++i;
continue;
}
if (i != 0 && str[i - 1] == ' ')
{
++i;
continue;
}
}
++i;
++cnt;
}
if (str[i - 1] == ' ')
{
--cnt;
}
return (cnt);
}
/**
 * token - mimics str token
 * @fstr: a filtered string
 * Return: token
 */
char *token(char *fstr)
{
char *prev;
int i;
static char *check = NULL;
static char *current = NULL;
i = 0;
if (fstr != check)
{
check = fstr;
current = fstr;
while (fstr[i] != '\0' && fstr[i] != ' ')
{
++i;
}
if (fstr[i] == ' ')
{
fstr[i] = '\0';
prev = current;
current = (current + i + 1);
return (prev);
}
else
{
if (i == 0)
{
return (NULL);
}
prev = current;
current = (current + i);
return (prev);
}
}
else
{
if (current[0] == '\0')
{
return (NULL);
}
while (current[i] != '\0' && current[i] != ' ')
{
++i;
}
if (current[i] == ' ')
{
current[i] = '\0';
prev = current;
current = (current + i + 1);
return (prev);
}
else
{
if (i == 0)
{
return (NULL);
}
prev = current;
current = (current + i);
}
}
return (prev);
}
/**
 * word_count - returns number of words in a filtered str
 * @str: filtered string
 * Return: int
 */
int word_count(char *str)
{
int i;
int cnt;
if (str[0] == '\0')
{
return (0);
}
cnt = 0;
i = 0;
while (str[i] != '\0')
{
if (str[i] == ' ')
{
++i;
++cnt;
}
++i;
}
++cnt;
return (cnt);
}
/**
 * fparser - returns each tokens(words) in a str
 * @fstr: filtered str
 * Return: ptrs to strs
 */
char **fparser(char *fstr)
{
int word_size;
int i;
char **para;
char *wtoken;
word_size = word_count(fstr);
para = (char **)malloc(sizeof(char *) * (word_size + 1));
if (para == NULL)
{
free(fstr);
malloc_error();
}
for (i = 0; i < word_size; ++i)
{
wtoken = token(fstr);
para[i] = (char *)malloc(sizeof(char) * (_strlen(wtoken) + 1));
if (para[i] == NULL)
{
free(fstr);
malloc_error();
}
strcpy(para[i], wtoken);
}
para[i] = NULL;
return (para);
}
