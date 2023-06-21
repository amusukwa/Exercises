#include <stdio.h>
#include <sys/stat.h>

int is_executable(const char *filename)
{
    struct stat file_stat;

    if (stat(filename, &file_stat) == -1) {
        perror("Error in stat");
        return 0;
    }

  
    if (S_ISREG(file_stat.st_mode) && (file_stat.st_mode & S_IXUSR)) {
        return 1; 
    }

    return 0; 
}

