#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _getenv - returns environ PATH
 * @name:input parameter
 * Return:character
 */
char * _getenv(const char *name)
{
    extern char **environ;

    size_t name_length = strlen(name);
    char *env_var;
    char **env;

    for (env = environ; *env != NULL; env++)
    {
        env_var = *env;
        if (strncmp(env_var, name, name_length) == 0 && env_var[name_length] == '=')
        {
            return &env_var[name_length + 1];
        }
    }

    return NULL;
}

