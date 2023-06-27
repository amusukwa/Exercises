#include "main.h"
/**
 * path_tokenizer - collects path tokens
 * @str: path;
 * Return: pointer to array
 */
char **path_tokenizer(char *str)
{
	char **path_array = NULL;
	char *path_token;
	int path_index = 0;

	path_array = malloc(MAX_VALUE * sizeof(char *));
	if (path_array == NULL)
	{
		return (NULL);
	}

        path_token = strtok(str, ":");
        while (path_token != NULL)
 	{
                 path_array[path_index] = path_token;
            	 path_index++;
                 path_token = strtok(NULL, ":");
	}
        path_array[path_index] = NULL;
                
          
        return (path_array);
}
