#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream) {
    static char buffer[BUFFER_SIZE];
    static ssize_t buffer_pos = 0;
    static ssize_t buffer_size = 0;
    ssize_t line_length = 0;
    char *line = NULL;
    char ch;
    const char *str;

    // Allocate initial memory for line buffer if needed
    if (*lineptr == NULL || *n == 0) {
        *n = BUFFER_SIZE;
        *lineptr = (char *)malloc(*n);
        if (*lineptr == NULL) {
            return -1; 
        }
    }

    while (1) {
        // If buffer is empty, read more characters from stream
        if (buffer_pos >= buffer_size) {
            buffer_size = read(fileno(stream), buffer, BUFFER_SIZE);
            if (buffer_size <= 0) {
                break;  // End of file or error encountered
            }
            buffer_pos = 0;
        }

        // Copy character from buffer to line
        ch = buffer[buffer_pos++];
        (*lineptr)[line_length++] = ch;

        // Resize line buffer if necessary
        if (line_length >= *n) {
            *n *= 2;
            char *new_lineptr = (char *)realloc(*lineptr, *n);
            if (new_lineptr == NULL) {
                return -1;  // Memory reallocation failed
            }
            *lineptr = new_lineptr;
        }

        // Check for newline character
        if (ch == '\n') {
            break;
        }
    }

    // Null-terminate the line
    (*lineptr)[line_length] = '\0';

    // Return line length or indicate end of file
    return (line_length > 1 || ch == '\n') ? line_length : -1;
}

