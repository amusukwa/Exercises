#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "Alias.h"


/**
 * find_alias - finds aliases
 * @name: alias name
 *

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

void print_alias(const char *name) {
	int i;
    Alias *alias = find_alias(name);
    if (alias != NULL) {
        for (i = 0; alias->name[i] != '\0'; i++) {
            putchar(alias->name[i]);
        }
        _putchar('=');
        for (i = 0; alias->value[i] != '\0'; i++) {
            putchar(alias->value[i]);
        }
      _putchar('\n');
    }
}*/

void print_all_aliases(){
	int i;
    Alias *current = alias_list;
    while (current != NULL) {
        for (i = 0; current->name[i] != '\0'; i++) {
           _putchar(current->name[i]);
        }
        _putchar('=');
        for (i = 0; current->value[i] != '\0'; i++) {
            _putchar(current->value[i]);
        }
       _putchar('\n');
        current = current->next;
    }
}
