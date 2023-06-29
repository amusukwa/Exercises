#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
* handle_exit - prints exit shell
* @argv:argument array
* @count:number of arguments
* Return:no return type
*/

void handle_exit(char **arguments, int count)
{

int exitStatus;
if (count == 1)
{
exit(0);
}
else if (count == 2)
{
exitStatus = _atoi(arguments[1]);
exit(exitStatus);
}
else
{
fprintf(stderr, "usage: exit [status]\n");
}
}
