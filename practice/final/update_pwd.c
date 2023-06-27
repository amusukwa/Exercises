#include "main.h"
/**
 * update_pwd_variable - updates pwd
 * @new_directory UNUSED: new directoy
 */
void update_pwd_variable(const char *new_directory UNUSED)
{
    char *cwd = get_current_directory();
    if (cwd != NULL)
    {
        setenv("PWD", cwd, 1);
        free(cwd);
    }
}
