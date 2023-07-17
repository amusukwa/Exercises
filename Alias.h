#ifndef ALIAS_H
#define ALIAS_H
#define MAX_NAME_LENGTH 64
#define MAX_VALUE_LENGTH 128

typedef struct Alias {
    char *name;
    char *value;
    struct Alias *next;
} Alias;



extern Alias *alias_list;
#endif                                                                                   
