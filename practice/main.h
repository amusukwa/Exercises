#ifndef MAIN_H
#define MAIN_H
#define BUFF_SIZE 1024
#define MAX_VALUE 10
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
int prompt_function(void);
char *main_str(int ac, char **av);
char *_strcpy(char *dest, char *src);
int _putchar(char c);
void print_prompt(const char *str);
#endif
