#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main (void)
{
	int fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	close(fd);
	return 0;
}
