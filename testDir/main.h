#ifndef MAIN_H
#define MAIN_H
#define BUFF_SIZE 1024
#define MAX_VALUE 10
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int prompt_function(void);
char *main_str(int ac, char **av);
char *_strcpy(char *dest, char *src);
int _putchar(char c);
void print_prompt(const char *str);
char *_strncat(char *dest, char *src, int n);
char * _getenv(const char *name);
int is_executable(const char *filename);
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
char *mystrtok(char *str, const char *delim);
int _atoi(char *s);
#endif
