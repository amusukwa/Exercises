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
	free(storage_buff);
	return (0);
	
}
