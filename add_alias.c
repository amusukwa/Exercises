#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "Alias.h"


/**
 * find_alias - finds aliases
 * @name: alias name
 */

Alias *find_alias(const char *name) {
     Alias *current = alias_list;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

/**
 * add_alias - handles adding aliases
 * @name: name alias
 * @value: value of alias
 * Return: no return type
 */
void add_alias(const char *name, const char *value) {
     Alias *alias = find_alias(name);
    if (alias != NULL) {
        free(alias->value); 
        alias->value = _strdup(value);
    } else {
        Alias *new_alias = (Alias *)malloc(sizeof(Alias));
        new_alias->name = _strdup(name); 
        new_alias->value = _strdup(value);  
        new_alias->next = alias_list;
        alias_list = new_alias;
    }
    
}

