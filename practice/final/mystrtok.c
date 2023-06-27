#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
* _strpbrk - searches a string for any of a set of bytes
* @s: input string
* @accept: set of bytes to search for
* Return: returns a pointer to the byte in s
*/
char *_strpbrk(char *s, const char *accept)
{
int k = 0;

while (*s) {
for (k = 0; accept[k]; k++) {
if (*s == accept[k])
return (s);
}
s++;
}

return ('\0');
}

/**
* mystrtok- separates input to words
* @str:input array
* @delim:second char input
* Return:size of iput stream
*/

char *mystrtok(char *str, const char *delim) {
    static char *token;
    static char *nextToken;
    char *result;

    if (str != NULL) {
        token = str;
    }


    result = token;
    nextToken = _strpbrk(token, delim);

    if (nextToken != NULL) {
        *nextToken = '\0';
        token = nextToken + 1;
    } else {
        token = NULL;
    }

    return result;
}
