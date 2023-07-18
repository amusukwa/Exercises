#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * _strchr-checks first occurence of character
 * @str: string to be checked
 * @c: character input
 *
 * Return: the address of the new element, or NULL if it fails
 */

const char *_strchr(const char *str, int c)
{
int i;

for (i = 0; str[i] != '\0'; i++)
{
if (str[i] == c)
{
return &str[i];
}
}

    return NULL;
}
