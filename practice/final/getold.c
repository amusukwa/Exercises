#include "main.h"
#include "string.h"
/**
 * get_old - gets path environment variable
 * @str: string containing path
 * Return: pointer to path
 */
char *get_old(void)
{
        char **env;
        env = environ;
        while (*env)
        {
                if (path_search(*env, "OLDPWD=", 7) == 0)
                {
                        return (*env + 7);
                }
                env++;
        }
        return (NULL);
}
