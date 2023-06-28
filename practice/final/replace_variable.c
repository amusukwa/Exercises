#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * replace_variables - replace variabes
 * @command: input 1
 * @status: input 2
 * @pid:input 3
 * Return: no return type
 */

void replace_variables(char *command, int status, pid_t pid)
{
char *temp = strdup(command);
char *result = malloc(_strlen(command) + 1);
char *token, *variable, *formatted;
if (temp == NULL || result == NULL)
{
perror("Error: Memory allocation failed");
free(temp);
free(result);
return;
}
formatted = malloc(strlen(command) + 16);
if (formatted == NULL)
{
perror("Error: Memory allocation failed");
free(temp);
free(result);
return;
}

token = strtok(temp, " ");

while (token != NULL)
{
if (token[0] == '$')
{
variable = token + 1;
if (strcmp(variable, "?") == 0)
{
sprintf(formatted, "%s %d", result, status);
}
else if (strcmp(variable, "$") == 0)
{
sprintf(formatted, "%s %d", result, pid);
}
else
{
sprintf(formatted, "%s %s", result, token);
}

strcpy(result, formatted);
}
else
{
sprintf(formatted, "%s %s", result, token);
strcpy(result, formatted);
}
token = strtok(NULL, " ");
}

strcpy(command, result);
free(temp);
free(result);
free(formatted);
}
