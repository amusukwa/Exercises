#include "main.h"
#include "string.h"
/**
 * getpath - gets path environment variable
 * @str: string containing path
 * Return: pointer to path
 */
char *getpath(void)
{
	char **env;
	env = environ;
	while (*env)
	{
		if (path_search(*env, "PATH=", 5) == 0)
		{
			return (*env + 5);
		}
		env++;
	}
	return (NULL);
}
