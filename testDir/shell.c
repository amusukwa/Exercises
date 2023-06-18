#include "main.h"
#include <string.h>

#define BUFF_SIZE 1024

/**
 * main - main shell function
 * Return: 0 on success
 */

    pid_t id;
    ssize_t line_length;
    const char *prompt_str = "$ ";
    char *storage_buff = NULL;
    size_t buff_size = BUFF_SIZE;
    
    while (1)
    {
        print_prompt(prompt_str);

        line_length = getline(&storage_buff, &buff_size, stdin);
        if (line_length == -1)
        {
            perror("getline");
            break;
        }
        if (strcmp(storage_buff, "exit") == 0)
            break;

        id = fork();
        if (id == -1)
        {
            perror("fork");
            break;
        }
        else if (id == 0)
        {
            char *argv[] = {storage_buff, NULL};
            int value = execve(argv[0], argv, NULL);
            if (value == -1)
                perror("execve");
            exit(EXIT_FAILURE);
        }
        else
        {
            wait(NULL);
        }
    }

    free(storage_buff);
    return 0;
}
