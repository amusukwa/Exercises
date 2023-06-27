#include "main.h"
#include <string.h>
/**
 * main - main shell function
 * Return: 0 on success
 */

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
        char *token;
        char **environment;
        char *path;
       char *path_token;
        char *path_command;
	
      int command_flag;

        while (1)
        {
                count = 0;

                prompt_str = "$ ";
                print_prompt(prompt_str);
                line_length = getline(&storage_buff, &buff_size, stdin);
                if (line_length == -1)
                {
			prompt_str = "$$";
			print_prompt(prompt_str);
			
                       /** _putchar('\n');*/
                        break;
                }
                _strcpy(input_command, storage_buff);

                token = strtok(input_command, " ");
                while (token != NULL && count < MAX_VALUE - 1)
                {
                        argv[count++] = token;
                        token = strtok(NULL, " ");
                }
                argv[count] = NULL;

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

                if ((_strcmp(argv[0], "exit")) == 0)
                        exit(0);

                if (input_command[0] == '/')
                {
                        id = fork();

                        if (id < 0)
                        {
                                perror("unsuccessful fork");
                                exit(1);
                        }
                        else if (id == 0)
                        {
                                value = execve(argv[0], argv, environ);
                                if (value == -1)
                                {
                                        perror("Error opening file");
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
                else
                {
                        path = getpath();
                        path_token = strtok(path, ":");
                        command_flag = 0;
                        while (path_token != NULL)
                        {
                                path_command = str_concat(path_token, argv[0]);
                                if (access(path_command, X_OK) == 0)
                                {
                                         id = fork();
                                         if (id < 0)
                                         {
                                                perror("unsuccessful fork");
                                                exit(1);
                                         }
                                        else if (id == 0)
                                        {
                                                value = execve(path_command, argv, environ);
                                                if (value == -1)
                                                {
                                                        perror("Error opening file");
                                                        exit(1);
                                                }
                                        }
                                        else
                                        {
                                                wait(NULL);
                                                command_flag = 1;
                                                free(path_command);
                                                break;
                                        }
                                }
                                

                         path_token = strtok(NULL, ":");
                        }

		if (!command_flag)
		printf("command not found");	

                }
		

        }
        return (0);
}


