#include "main.h"
/**
 * buffer_function - creates a buffer
 * @filename: name of file
 * Return: pointer to buffer
 */
char *buffer_function(char *filename)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}
	return (buffer);
}
