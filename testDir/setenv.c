#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "main.h"

int _setenv(const char *name, const char *value, int overwrite) 
{
*name = "MY_VARIABLE";
*value = "Hello, world!";
const char prompt_str;

if (setenv(name, value, 1) == 0)
{
prompt_str = "Environment variable"
print_prompt();
}
else
{
perror("Failed to set environment variable");
}

return 0;
}

