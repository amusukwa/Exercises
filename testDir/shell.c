#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

#define BUFF_SIZE 1024

extern char **environ;

int main(void)
{
    pid_t id;
    const char *prompt_str;
    int count;
    size_t buff_size = 1024;
    ssize_t line_length;
    int value;
    char *storage_buff = NULL;
    char input_command[BUFF_SIZE];
    char *argv[MAX_VALUE];
    char *token, *path, *dir;

    while (1)
    {
        count = 0;

        prompt_str = "$ ";
        printf("%s", prompt_str);
        line_length = getline(&storage_buff, &buff_size, stdin);
        if (line_length == -1)
        {
            putchar('\n');
            break;
        }
        storage_buff[line_length - 1] = '\0';

        strcpy(input_command, storage_buff);

        token = strtok(input_command, " ");
        while (token != NULL && count < MAX_VALUE - 1)
        {
            argv[count++] = token;
            token = strtok(NULL, " ");
        }
        argv[count] = NULL;

        if (strcmp(argv[0], "exit") == 0)
            exit(0);

        id = fork();

        if (id < 0)
        {
            perror("unsuccessful fork");
            exit(1);
        }
        else if (id == 0)
        {
            
            if (is_executable(argv[0]) == 1)
            {
                value = execve(argv[0], argv, NULL);
            }
            else
            {
                
                path = _getenv("PATH");
                if (path != NULL)
                {
                    
                    dir = strtok(path, ":");
                    while (dir != NULL)
                    {
                        
                        snprintf(input_command, sizeof(input_command), "%s/%s", dir, argv[0]);
                        
                        if (access(input_command, X_OK) == 0)
                        {
                            value = execve(input_command, argv, NULL);
                            break;
                        }
                        dir = strtok(NULL, ":");
                    }
                }
            }

            if (value == -1)
            {
                perror("Error executing command");
                exit(1);
            }

            free(storage_buff);
            exit(1);
        }
        else
        {
            wait(NULL);
        }
    }
    free(storage_buff);
    return 0;
}


