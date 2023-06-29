#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * str_concat - concatenates strings
 * @s1: string 1
 * @s2: string 2
 * Return: pointer of new string
 */
char *str_concat(char *s1, char *s2)
{
size_t len_str1 = 0;
size_t len_str2 = 0;
size_t i;
char *combined_str;

while (s1[len_str1] != '\0')
{
len_str1++;
}
while (s2[len_str2] != '\0')
{
len_str2++;
}
combined_str = malloc((len_str1 + len_str2 + 2) * sizeof(char));
if (combined_str == NULL)
{ 
	return NULL;
}

for (i = 0; i < len_str1; i++)
{
combined_str[i] = s1[i];
}
combined_str[len_str1] = '/';
for (i = 0; i < len_str2; i++)
{
combined_str[len_str1 + 1 + i] = s2[i];
}
combined_str[len_str1 + len_str2 + 1] = '\0';
return (combined_str);
}
