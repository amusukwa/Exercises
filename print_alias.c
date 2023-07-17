#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "Alias.h"


/**
 * search_alias - finds aliases
 * @name: alias name
 */

Alias *search_alias(const char *name) {
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
 * print_alias - prints aliases
 * @name: alias name
 */

void print_alias(const char *name) {
        int i;
    Alias *alias = search_alias(name);
    if (alias != NULL) {
        for (i = 0; alias->name[i] != '\0'; i++) {
            _putchar(alias->name[i]);
        }
        _putchar('=');
        for (i = 0; alias->value[i] != '\0'; i++) {
            _putchar(alias->value[i]);
        }
      _putchar('\n');
    }
}

