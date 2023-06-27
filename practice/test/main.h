#ifndef MAIN_H
#define MAIN_H
#define BUFF_SIZE 1024
#define MAX_VALUE 10
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
extern char **environ;
char *getpath(void);
char **path_tokenizer(char *str);
int path_search(const char *str1, const char *str2, size_t count);
char *str_concat(char *s1, char *s2);
int _strlen(const char *s);
int prompt_function(void);
char *main_str(int ac, char **av);
char *gethome(void);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _putchar(char c);
void print_prompt(const char *str);
#endif
