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
    int count;
    size_t buff_size = 1024;
    ssize_t line_length;
    int value, found;
    char *storage_buff = NULL;
    char input_command[BUFF_SIZE];
    char *argv[MAX_VALUE];
    char *token, *path, *dir;

    while (1) {
        count = 0;

        prompt_str = "$ ";
        print_prompt(prompt_str);
        line_length = getline(&storage_buff, &buff_size, stdin);
        if (line_length == -1) {
            putchar('\n');
            break;
        }
        storage_buff[line_length - 1] = '\0';  

        strcpy(input_command, storage_buff);

        token = strtok(input_command, " ");
        while (token != NULL && count < MAX_VALUE - 1) {
            argv[count++] = token;
            token = strtok(NULL, " ");
        }
        argv[count] = NULL;

        found = 0;
       	path = getenv("PATH");
        dir = strtok(path, ":");
            while (dir != NULL) 
	    {

                char buffer[BUFF_SIZE];
                snprintf(buffer, sizeof(buffer), "%s/%s", dir, argv[0]);
                if (access(buffer, X_OK) == 0) {
                    found = 1;
                    id = fork();
                    if (id < 0) {
                        perror("unsuccessful fork");
                        exit(1);
                    } else if (id == 0) {
                        value = execve(buffer, argv, environ);
                        if (value == -1) {
                            perror("Error opening file");
                            exit(1);
                        }
                        free(storage_buff);
                        exit(1);
                    } else {
                        wait(NULL);
                    }
                    break;
                }
                dir = strtok(NULL, ":");
		  }
	     if (!found)
	     {
            printf("Command not found: %s\n", argv[0]);
        }
	     free(storage_buff);
	}
	 free(storage_buff);
}
    return 0;
}


