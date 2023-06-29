#include "main.h"
/**
 * close_file - closes file descriptor
 * @fd: file desciptor
 */
void close_file(int fd)
{
	int n;

	n = close(fd);
	if (n == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
