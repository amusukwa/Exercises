#include <stdio.h>
#include "main.h"
/**
 * print_prompt - prints specified string
 * Description: uses putchar to print string
 * @str: string to be printed
 * Return: void
 */
void print_prompt(const char *str)
{
int i = 0;

while (str[i] != '\0')
{
_putchar(str[i]);
i++;
}
}
