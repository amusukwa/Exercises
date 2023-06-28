#include "main.h"
#define UNUSED __attribute__((unused))


/**
 * update_pwd_variable - updates pwd
 * @new_directory: new directory path
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
