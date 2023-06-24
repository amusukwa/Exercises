#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * handle_setenv - prints character
 * @variable: character c
 * @value:char input
 * Return: 1 if successful -1 on error
 */

void handle_setenv(const char *variable, const char *value) {
    if (setenv(variable, value, 1) != 0) {
        perror("Failed to set environment variable");
    }
}

/**
 * handle_unsetenv - prints character
 * @variable: character c
 * @value:char input
 * Return: 1 if successful -1 on error
 */

void handle_unsetenv(const char *variable) {
    if (unsetenv(variable) != 0) {
        perror("Failed to unset environment variable");
    }
}

int main(void) {
    

    while (1) {
        

        if (_strcmp(argv[0], "setenv") == 0) {
            
        } else if (_strcmp(argv[0], "unsetenv") == 0) {
            
            if (count == 2) {
                handle_unsetenv(argv[1]);
            } else {
                perror( "usage: unsetenv VARIABLE");
            }
        } else {
            
        }
    }

    return (0);
}

