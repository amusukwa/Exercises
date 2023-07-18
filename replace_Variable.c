#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include "Alias.h"

int last_command_exit_status = 0;
void _memmove(void *dest, const void *src, size_t n)
{
    char *destination = (char *)dest;
    const char *source = (const char *)src;
    size_t i;

    if (destination > source && destination < source + n)
    {
        
        for (i = n; i > 0; i--)
        {
            destination[i - 1] = source[i - 1];
        }
    }
    else
    {
        
        for (i = 0; i < n; i++)
        {
            destination[i] = source[i];
        }
    }

   /* return dest;*/
}
/**
 * Set the exit status of the last command.
 * @status: The exit status of the last command.
 */

void set_exit_status(int status){
	
    	 last_command_exit_status = status;
}


/**
 * replace_variable - replaces special variables and regular variables
 * @input: the input string to process
 *
* Return: a new string with variables replaced, or NULL on failure
 */
char *replace_variable(char *input){
    char *result = NULL;
    char *pos, *end;
    char var_name[MAX_VALUE];
    char *var_value;
    


    if (input == NULL)
        return NULL;

    result = strdup(input);
    if (result == NULL)
        return NULL;

    while ((pos = strstr(result, "$?")) != NULL) {
        snprintf(var_name, sizeof(var_name), "%d", last_command_exit_status);
        end = pos + 2;
        _memmove(pos, var_name, strlen(var_name) + 1);
        pos = end;
    }
    while ((pos = strstr(result, "$$")) != NULL)
    {
        snprintf(var_name, sizeof(var_name), "%d", getpid());
        end = pos + 2;
        _memmove(pos, var_name, strlen(var_name) + 1);
        pos = end;
    }

    
    pos = result;
    while (*pos) {
        if (*pos == '$')
	{
            
            end = pos + 1;
            while (*end && (*end == '_' || (*end >= 'A' && *end <= 'Z') || (*end >= 'a' && *end <= 'z')))
                end++;
            strncpy(var_name, pos + 1, end - pos - 1);
            var_name[end - pos - 1] = '\0';

            
            var_value = getenv(var_name);
            if (var_value != NULL) {
              
                _memmove(pos, var_value, strlen(var_value) + 1);
            } else {
                
               _memmove(pos, pos + 1, strlen(pos));
            }
        } else {
            pos++;
        }
    }

    return result;
}
