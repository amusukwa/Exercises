
#include "main.h"


/**
 * execute_command - executes input
 * @command: input char
 * Return: no return type
 */


void execute_command(const char* command) {
 
    int status = system(command);
    int exit_status, signal_number;

    if (status == -1) {
        perror("Command execution error");
    } else {
        if (WIFEXITED(status)) {
             exit_status = WEXITSTATUS(status);
            printf("Command exited with status: %d\n", exit_status);
        } else if (WIFSIGNALED(status)) {
            signal_number = WTERMSIG(status);
            printf("Command terminated by signal: %d\n", signal_number);
        }
    }
}

