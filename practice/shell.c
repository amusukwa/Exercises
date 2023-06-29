#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define UNUSED __attribute__((unused))

void update_pwd_variable(const char *new_directory);

char *get_current_directory(void)
{
    char *cwd = malloc(MAX_PATH_LENGTH);
    if (cwd != NULL)
        getcwd(cwd, MAX_PATH_LENGTH);
    return cwd;
}

void update_pwd_variable(const char *new_directory UNUSED)
{
    char *cwd = get_current_directory();
    if (cwd != NULL)
    {
        setenv("PWD", cwd, 1);
        free(cwd);
    }
}

void handle_cd(const char *directory)
{
    char *new_directory, *previous_directory;

    if (directory == NULL || directory[0] == '\0' || strcmp(directory, "~") == 0)
    {
        new_directory = getenv("HOME");
        if (new_directory == NULL)
        {
            perror("cd: no $HOME directory");
            return;
        }
    }
    else if (strcmp(directory, "-") == 0)
    {
        new_directory = getenv("OLDPWD");
        if (new_directory == NULL)
        {
            perror("cd: no previous directory");
            return;
        }
        _putchar('\n');
        _puts(new_directory);
       _putchar('\n');
    }
    else
    {
        new_directory = (char *)directory;
    }

    previous_directory = get_current_directory();
    if (previous_directory != NULL)
    {
        if (chdir(new_directory) == 0)
        {
            setenv("OLDPWD", previous_directory, 1);
            update_pwd_variable(new_directory);
        }
        else
        {
            perror("cd failed");
        }
        free(previous_directory);
    }
   
}

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
                        path_index = 0;
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
		
	//	if ((_strcmp(argv[0], "cd")) == 0)
	//	{
	//		if (count == 0)
	//		{
	//			chdir(gethome());
	//		}
	//		if (count == 1)
	//		{
	//			chdir(argv[1]);
	//		}
	//		if (count > 2)
	//			perror("cd");
	//		continue;
		//}
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
			for (int i = 0; i < path_index; i++)
				printf("%s\n", path_array[i]);
		}
		
                }//while loop closing brace

        return (0);
}
