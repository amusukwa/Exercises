#include "main.h"

/**
 * handle_setenv - prints character
 * @variable: character c
 * @value:char input
 * Return: no return type
 */

void handle_setenv(const char *variable, const char *value, int overwrite)
{
if (setenv(variable, value, overwrite) != 0) {
perror("Failed to set environment variable");
}
}
