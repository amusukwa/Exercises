#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - Simple shell function
 * Return: 0 on success
 */
int main(void)
{
    pid_t id;
    pid_t id_1;
    const char *prompt_str;
    int count;
    size_t buff_size = 1024;
    ssize_t line_length;
    int value, value_1, x;
    char *storage_buff = NULL;
    char input_command[BUFF_SIZE];
    char *argv[MAX_VALUE];
    char *token;
    char **environment;
    char *path, *path_token;
    char *path_command;
    int path_index = 0;
    char *path_array[MAX_VALUE];

    while (1)
    {
        count = 0;
        prompt_str = "$ ";
        print_prompt(prompt_str);
        line_length = my_getline(&storage_buff, &buff_size, stdin);
        if (line_length == -1)
        {
            perror("input");
            _putchar('\n');
            break;
        }
        if (line_length == 1)
        {
            perror("Empty input");
            continue;
        }
        _strcpy(input_command, storage_buff);
        if (input_command == NULL)
        {
            perror("No command found");
            exit(98);
        }
        token = strtok(input_command, " ");
        while (token != NULL && count < MAX_VALUE - 1)
        {
            argv[count++] = token;
            token = strtok(NULL, " ");
        }
        argv[count] = NULL;

        path = getpath();
        path_token = strtok(path, ":");
        while (path_token != NULL)
        {
            path_array[path_index] = path_token;
            path_index++;
            path_token = strtok(NULL, ":");
        }
        path_array[path_index] = NULL;
	
       	/* Print environment variables */
        if ((_strcmp(argv[0], "env")) == 0)
        {
            environment = environ;
            while (*environment)
            {
                print_prompt(*environment);
                environment++;
                _putchar('\n');
            }
            continue;
        }
	if (_strcmp(argv[0], "exit") == 0) {
            handle_exit(argv, count);
        }

        if (_strcmp(argv[0], "setenv") == 0)
        {
            if (count == 3)
            {
                setenv(argv[1], argv[2], 1);
            }
            else
            {
                perror("setenv failed");
            }
        }

        if (_strcmp(argv[0], "unsetenv") == 0)
        {
            if (count == 2)
            {
                unsetenv(argv[1]);
            }
            else
            {
                perror("usage: unsetenv VARIABLE");
            }
        }

        if (_strcmp(argv[0], "cd") == 0)
        {
            if (count == 1)
            {
                handle_cd(NULL);
            }
            else if (count == 2)
            {
                handle_cd(argv[1]);
            }
            else
            {
                perror("usage: cd [directory]");
            }
            continue;
        }

        if (input_command[0] == '/')
        { 
	
	/* Handle fork processes */
            
	    id = fork();

            if (id < 0)
            {
          
	        handle_error("unsuccessful fork");
                exit(1);
            }
            else if (id == 0)
            {
                value = execve(argv[0], argv, environ);
                if (value == -1)
                {
	            handle_error("Error opening file");
                    free(storage_buff);
                    exit(1);
                }
            }
            else
            {
		/* Parent process */
                wait(NULL);
            }
        }

        if (input_command[0] != '/' && (_strcmp(argv[0], "exit")) != 0 && (_strcmp(argv[0], "cd")) != 0 && (_strcmp(argv[0], "env")) != 0)
        {
            for (x = 0; x < path_index; x++)
            {
                path_command = str_concat(path_array[x], argv[0]);
                if (access(path_command, X_OK) == 0)
                {
                    id_1 = fork();
                    if (id_1 < 0)
                    {
                        perror("unsuccessful fork");
                        exit(1);
                    }
                    else if (id_1 == 0)
                    {
                        value_1 = execve(path_command, argv, environ);
                        if (value_1 == -1)
                        {
                            perror("Error opening file");
                            exit(1);
                        }
                    }
                    else
                    {
                        wait(NULL);
                    }
                    free(path_command);
                    break;
                }
            }
        }
    }
    return (0);
}


