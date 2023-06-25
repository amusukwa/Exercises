#include "main.h"
/**
 * handle_unsetenv - prints character
 * @variable: character c
 * @value:char input
 * Return: no return type
 */

void handle_unsetenv(const char *variable) {
    if (unsetenv(variable) != 0) {
        perror("Failed to unset environment variable");
    }
}

