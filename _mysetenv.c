#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @name: name of new environment variable
 * @value:value of new environment variable
 *  
 *  Return: Always 0
 */

int mysetenv(const char *name, const char *value)
{
    if (name == NULL || value == NULL) 
    {
        _puts("Error: Invalid arguments for mysetenv\n");
        return -1; 
    }

    
    if (setenv(name, value, 1) != 0)
    {
        perror("setenv");
        return -1;
    }

    return 0;
}



/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */

int _mysetenv(int argc, char argv[])
{
	if( argc != 3)
	{
		_puts("Incorrect number of arguements\n");
		return (1);
	}
	if (mysetenv(argv[1], argv[2]) == 0)
	{
        return 0;
    } else {
       _puts(stderr, "Failed to set environment variable\n");
        return 1; // Failure
    }
}

