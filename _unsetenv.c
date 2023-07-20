#include "main.h"
#include "list.h"


/**
 * _unsetenv - Remove an environment variable
 * @env: Pointer to the head of the environment linked list.
 * @var: The name of the environment variable to remove.
 * Return: 1 on delete, 0 otherwise
 */
int _unsetenv(list_t **env, const char *var)
{
    list_t *current = *env;
    list_t *prev = NULL;
    size_t i = 0;
    char *p;

    if (!current || !var)
        return 0;

    while (current)
    {
        p = starts_with(current->str, var);
        if (p && *p == '=')
        {
            if (prev == NULL)
                *env = current->next;
            else
                prev->next = current->next;

            free(current->str);
            free(current);
            return 1;
        }
        prev = current;
        current = current->next;
        i++;
    }
    return 0;
}



/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myunsetenv(int argc, char *argv[])
{
	int i;

	if (argc == 1)
	{
		_puts("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= argc; i++)
		_unsetenv( argv[i]);

	return (0);
}
