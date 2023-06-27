#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * handle_cd - handles directories
 * @directory: current working directory
 */

void handle_cd(const char *directory)
{
    char *new_directory, *previous_directory;

    if (directory == NULL || directory[0] == '\0' || _strcmp(directory, "~") == 0)
    {
        new_directory = (char *)gethome();
        if (new_directory == NULL)
        {
            perror("cd: no $HOME directory");
            return;
        }
    }
    else if (strcmp(directory, "-") == 0)
    {
        new_directory = get_old();
        if (new_directory == NULL)
        {
            perror("cd: no previous directory");
            return;
        }
        _putchar('\n');
        _puts(new_directory);
        _putchar('\n');
    }
    else
    {
        new_directory = (char *)directory;
    }

    previous_directory = get_current_directory();
    if (previous_directory != NULL)
    {
        if (chdir(new_directory) == 0)
        {
            setenv("OLDPWD", previous_directory, 1);
            update_pwd_variable(new_directory);
        }
        else
        {
            perror("cd failed");
        }
        free(previous_directory);
    }
}
