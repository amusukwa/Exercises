#include "main.h"
#include <string.h>
/**
 * main - main shell function
 * Return: 0 on success
 */

int main(void)
{
	pid_t id;
	int i, n = 0;
	const char *prompt_str;
	size_t buff_size = 1024;
	ssize_t line_length;
	int value;
	char *storage_buff = NULL;
	char input_command[buff_size];
	char *argv[] = {input_command, NULL};

	while (1)
	{
		prompt_str = "$ ";
		print_prompt(prompt_str);
		line_length = getline(&storage_buff, &buff_size, stdin);
		if (line_length == -1)
		{
			break;
		}
		_strcpy(input_command, storage_buff);

		id = fork();

		if (id < 0)
		{
			perror("unsuccessful fork");
			exit(1);
		}
		else if (id == 0)
		{
			value = execve(argv[0], argv, NULL);
			free(storage_buff);
			exit(1);
		}
	        else 
		{
			wait(NULL);
		}
	}
	
}
