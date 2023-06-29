#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024
/**
* my_getline - reads input to stream
* @lineptr:input line
* @n:size of buffer
* @stream:stream
* Return:size of iput stream
*/
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
static char buffer[BUFFER_SIZE];
static ssize_t buffer_pos, buffer_size;
ssize_t line_length = 0;
char  *new_lineptr, ch;

if (*lineptr == NULL || *n == 0)
{
*n = BUFFER_SIZE;
*lineptr = (char *)malloc(*n);
if (*lineptr == NULL)
{
return (-1);
}
}
while (1)
{
if (buffer_pos >= buffer_size)
{
buffer_size = read(fileno(stream), buffer, BUFFER_SIZE);
if (buffer_size <= 0)
{
break;
}
buffer_pos = 0;
}
ch = buffer[buffer_pos++];
(*lineptr)[line_length++] = ch;
if ((size_t)line_length >= *n)
{
*n *= 2;
new_lineptr = (char *)realloc(*lineptr, *n);
if (new_lineptr == NULL)
{
return (-1);
}
*lineptr = new_lineptr;
}
if (ch == '\n')
{
break;
}
}
(*lineptr)[line_length] = '\0';
return ((line_length > 1 || ch == '\n') ? line_length : -1);
}

