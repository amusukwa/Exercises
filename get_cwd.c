#include "main.h"
/**
* get_current_directory - gets cwd
* Return: pointer to new directory
*/
char *get_current_directory(void)
{
char *cwd = malloc(MAX_PATH_LENGTH);
if (cwd != NULL)
getcwd(cwd, MAX_PATH_LENGTH);
return (cwd);
}
