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
        int value, command_flag;
        char *storage_buff = NULL;
        char input_command[BUFF_SIZE];
        char *argv[MAX_VALUE];
        char *token;
        char **environment;
        char *path, *path_token;
        char *path_command; 	

        while (1)
        {
                count = 0;

                prompt_str = "$ ";
                print_prompt(prompt_str);
                line_length = my_getline(&storage_buff, &buff_size, stdin);
                if (line_length == -1)
                {
                        _putchar('\n');
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
		{
		if (count == 1)
		{
                 exit(0);
               } 
		else if (count == 2)
	    {
                
                int exitStatus = _atoi(argv[1]);
                exit(exitStatus);
            } 
		else {
                
                perror("usage: exit status");
            	}
		} 
	      	if (_strcmp(argv[0], "setenv") == 0)
		 {
                 if (count == 3)
		 {
        	handle_setenv(argv[1], argv[2], 1);
    		}
   		 else {
        		perror("setenv failed");
    		}

       		 }
       if (_strcmp(argv[0], "unsetenv") == 0)
       {
            if (count == 2) {
                handle_unsetenv(argv[1]);
            } else {
                printf("usage: unsetenv VARIABLE\n");
            }
        }
                  

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
						if (path_command != NULL) 
						{
						    free(path_command);
							}
                                                     break;
                                        }
                                }
                                

                         path_token = strtok(NULL, ":");
                        }

		if (!command_flag)
			perror("Command not found");

                }
		

        }
        return (0);
}


