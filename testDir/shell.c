#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define BUFF_SIZE 1024

extern char **environ;

int main(void) {
    pid_t id;
    const char *prompt_str;
    int count, found;
    size_t buff_size = 1024;
    ssize_t line_length;
    char *storage_buff = NULL;
    char input_command[BUFF_SIZE];
    char *argv[MAX_VALUE];
    const char *cmd_not_found = "Command not found: ";
    char *token, *path, *dir, *ptr;
    char buffer[BUFF_SIZE];

   
    if (getenv("PATH") == NULL) {
        setenv("PATH", "/bin", 1);
    }

    while (1) {
        count = 0;

        prompt_str = "$ ";
        print_prompt(prompt_str);
        line_length = getline(&storage_buff, &buff_size, stdin);
        if (line_length == -1) {
            putchar('\n');
            break;
        }
        strncpy(input_command, storage_buff, sizeof(input_command));

        token = strtok(input_command, " ");
        while (token != NULL && count < MAX_VALUE - 1) {
            argv[count++] = token;
            token = strtok(NULL, " ");
        }
        argv[count] = NULL;

        found = 0;
        path = getenv("PATH");
        dir = strtok(path, ":");
        while (dir != NULL) {
            strncpy(buffer, dir, sizeof(buffer));
            strncat(buffer, "/", sizeof(buffer) - strlen(buffer) - 1);
            strncat(buffer, argv[0], sizeof(buffer) - strlen(buffer) - 1);

            if (access(buffer, X_OK) == 0) {
                found = 1;
                id = fork();
                if (id < 0) {
                    perror("fork");
                    exit(1);
                } else if (id == 0) {
                    execve(buffer, argv, environ);
                    perror("execve");
                    exit(1);
                } else {
                    wait(NULL);
                }
                break;
            }
            dir = strtok(NULL, ":");
        }

        if (!found) {
            printf("%s%s\n", cmd_not_found, argv[0]);
        }

        free(storage_buff);
        storage_buff = NULL;
    }

    free(storage_buff);
    return 0;
}


