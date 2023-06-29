#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define MAX_COMMAND_LENGTH 1024

/**
 * main - simple shell function
 * Return: 0 on success
 */
int main(int argc, char* argv[])
{

    pid_t id, id_1;

	if (argc > 1)
	{

	FILE* file;
	char* line = NULL;
	int file_descriptor;
        size_t line_length = 0;
        ssize_t read;
	
	if (argc != 2)
	{
	handle_error("Usage:  [filename]");
	return (1);
	}
        
	 file_descriptor = open(argv[1], O_RDONLY);
        if (file_descriptor == -1)
	{
            _puts("Failed to open file:");
            return 1;
        }
	
	file = fdopen(file_descriptor, "r");
        if (file == NULL)
	{
            _puts("Failed to open file");
            close(file_descriptor);
            return 1;
        }

	while ((read = my_getline(&line, &line_length, file)) != -1)
	{
            if (line[read - 1] == '\n')
	    {
                line[read - 1] = '\0';
		execute_command(line);
            }
	}

	free(line);
        close(file_descriptor);
        return 0;
	}


    
   else
   {

   /* Interactive mode */

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
	line_length = getline(&storage_buff, &buff_size, stdin);
	
	if (line_length == -1)
	{
	/**	perror("input");*/
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
	/**	free(path);*/

        path_array[path_index] = NULL;

	/* handle environment */

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
            else
            {
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
            else
            {
                perror("usage: cd [directory]");
            }
            continue;
	}

        if (input_command[0] == '/')
        {
	/* Child processes */
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
                    free(storage_buff);
                    exit(1);
                }
            }
            else
            {
	    /* parent process */
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
					
                                         
                                         break;
                    }
			       free(path_command);
                            }
                
                 
                }
	   
    }
   }

    return (0);
}


