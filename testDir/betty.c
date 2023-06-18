#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
/**
 * _putchar - writes the character c to stdout
 *
 * @c: Character to print out
 *
 * Return: 1 Always (Success)
 *
 * On error -1 is returned and errno is set appropriately
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}       

/**
 * main - prints prompt
 *
 * Return: no return type
 */
int main() {
char prompt = '$';

_putchar(prompt);
_putchar('\n');


return 0;
}
