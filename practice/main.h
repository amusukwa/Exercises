#ifndef MAIN_H
#define MAIN_H
#define BUFF_SIZE 1024
#define MAX_VALUE 10
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
extern char **environ;
char *getpath(void);
int path_search(const char *str1, const char *str2, size_t count);
char *str_concat(char *s1, char *s2);
int _strlen(const char *s);
int prompt_function(void);
char *main_str(int ac, char **av);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _putchar(char c);
void print_prompt(const char *str);
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
char *mystrtok(char *str, const char *delim);
int _atoi(char *s);
void handle_cd(const char *directory); 
void handle_setenv(const char *variable, const char *value,int overwrite); 
void handle_unsetenv(const char *variable); 
void replace_variables(char *command, int status, pid_t pid);
#endif
