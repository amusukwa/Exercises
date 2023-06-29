#include "main.h"
#include "string.h"
/**
 * gethome - gets path environment variable
 * Return: pointer to path
 */
char *gethome(void)
{
char **env;
env = environ;
while (*env)
{
if (path_search(*env, "HOME=", 5) == 0)
{
return (*env + 5);
}
env++;
}
return (NULL);
}
