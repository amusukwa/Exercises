#ifndef MAIN_H
#define MAIN_H
#define BUFF_SIZE 1024
#define MAX_VALUE 10
#define MAX_PATH_LENGTH 1024
#define UNUSED __attribute__((unused))
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
extern char **environ;
char *getpath(void);
int path_search(const char *str1, const char *str2, size_t count);
char *str_concat(char *s1, char *s2);
int prompt_function(void);
char *main_str(int ac, char **av);
char *_strcpy(char *dest, char *src);
void handle_cd(const char *directory);
int _putchar(char c);
char *get_old(void);
int _strcmp(const char *s1, const char *s2);
char *gethome(void);
void print_prompt(const char *str);
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
char *mystrtok(char *str, const char *delim);
int _atoi(const char *s);
void handle_cd(const char *directory); 
void handle_setenv(const char *variable, const char *value,int overwrite); 
void handle_unsetenv(const char *variable); 
void update_pwd_variable(const char *new_directory);
char *get_current_directory(void);
void replace_variables(char *command, int status, pid_t pid);
void _puts(const char *str);
int _strlen(char *s);
void handle_error(const char *message);
void handle_exit(char **argv, int count);
#endif
