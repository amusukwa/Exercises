#include "main.h"
int main(void)
{
        pid_t id;
	pid_t id_1;
        const char *prompt_str;
        int count;
        size_t buff_size = 1024;
        ssize_t line_length;
        int value, value_1;
        char *storage_buff = NULL;
        char input_command[BUFF_SIZE];
        char *argv[MAX_VALUE];
        char *token;
        char **environment;
        char *path;
        char *path_token;
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

                //path tokenizer
                        path = getpath();
                        path_token = strtok(path, ":");
                        while (path_token != NULL)
                        {
                                path_array[path_index] = path_token;
                                path_index++;
                                path_token = strtok(NULL, ":");
                        }
                        path_array[path_index] = NULL;

                //end of path tokenize
                // built in commands

                if (input_command[0] == '#')
                        continue;

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

                //end of built in commands

                //path specified commands
                if (input_command[0] == '/')
                {
                        if (access(argv[0], X_OK) == 0)
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
                                        perror("Execve");
                                        exit(1);
                                }
                                free(storage_buff);
                                exit(0);
                        }
                        else
                        {
                                wait(NULL);
                        }
                }
                else
                {
                        perror("command not found");
                        continue;
                }
                }//end of path specified commands

                if (input_command[0] != '/')
                {
                       for (int x = 0; x < path_index; x++)
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

                }//while loop closing brace

        return (0);
}
