#ifndef LIST_H
#define LIST_H
~          
typedef struct list_node {
    char *str;              
    struct list_node *next;
} list_t;

extern list_t *list;

#endif
