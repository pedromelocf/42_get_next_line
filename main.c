#include "get_next_line.h"
#include <fcntl.h>

int main (void)
{
	int fd;

	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	close(fd);
	return 0;
}
