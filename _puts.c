#include "main.h"

/**
 * _puts - writes string to stdout
 *
 * @str: Character to print out
 *
 * Return: no return type
 */

void _puts( char *str)
{
int i = 0;

while (str[i] != '\0')
{
_putchar(str[i]);
i++;
}
}
