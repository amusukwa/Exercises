#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024
/**
* handle_error - prints error 
* @message:input string
* Return:no return type
*/

void handle_error(const char *message)
{
perror(message);
exit(1);
}

