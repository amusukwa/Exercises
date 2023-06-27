#include "main.h"
/**
 * path_search - searches for path in environment variables
 * @str1: string one to compare
 * @str2: string two to compare
 * @count: number of characters to compare
 * Return: 0 if successful
 */
int path_search(const char *str1, const char *str2, size_t count)
{
while (count > 0)
{
if (*str1 != *str2)
return (*str1 - *str2);
if (*str1 == '\0')
return (0);
str1++;
str2++;
count--;
}
return (0);
}
