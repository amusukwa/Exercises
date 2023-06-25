#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define MAX_PATH_LENGTH 1024

/**
 * handle_cd - directory
 * @directory: character input
 * Return: no return type
 */

/**
void handle_cd(const char *directory) {
    char prev_dir[MAX_PATH_LENGTH];
    char *new_dir;

    if (directory == NULL || strcmp(directory, " ") == 0 || strcmp(directory, "~") == 0)
    {
        new_dir = getenv("HOME");
    }
    else if (strcmp(directory, "-") == 0) 
    {
        new_dir = prev_dir;
    }
    else 
    {
        new_dir = (char *)directory;
    }

    if (new_dir == NULL)
    {
        perror("cd failed: Directory not found");
        return;
    }

    if (getcwd(prev_dir, sizeof(prev_dir)) == NULL)
    {
        perror("getcwd failed");
        return;
    }

    if (chdir(new_dir) != 0)
    {
        perror("cd failed");
        return;
    }

    if (getcwd(prev_dir, sizeof(prev_dir)) == NULL)
    {
        perror("getcwd failed");
        return;
    }

    setenv("PWD", prev_dir, 1);
}
*/

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
       	else {
        perror("usage: cd [directory]");
   	 }
  	  continue; 
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
