#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

extern char **environ;

int mysetenv(const char *name, const char *value)
{
	char **env_ptr;
	char *new_env ;
	size_t len;
	 int num_env; 
	char **new_environ;
    if (name == NULL || value == NULL) {
        _puts( "Error: Invalid arguments for mysetenv\n");
        return -1;
    }

  
    env_ptr = environ;
    while (*env_ptr != NULL) {
        if (strncmp(*env_ptr, name, strlen(name)) == 0)
	{
            free(*env_ptr);
            *env_ptr = strdup(name);
            if (*env_ptr == NULL) {
                perror("strdup");
                return -1;
            }
            return 0;
        }
        env_ptr++;
    }

 
    len = strlen(name) + strlen(value) + 2;
    new_env = malloc(len);
    if (new_env == NULL) {
        perror("malloc");
        return -1;
    }
    snprintf(new_env, len, "%s=%s", name, value);

   
     num_env = 0;
    while (environ[num_env] != NULL) {
        num_env++;
    }

  
    new_environ = realloc(environ, (num_env + 2) * sizeof(char *));
    if (new_environ == NULL) {
        perror("realloc");
        free(new_env);
        return -1;
    }
    new_environ[num_env] = new_env;
    new_environ[num_env + 1] = NULL;

   
    environ = new_environ;
    return 0;
}

