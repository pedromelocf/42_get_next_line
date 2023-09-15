#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char		*line;
	int			fd;
	int			counter;

	fd = open("test.txt", O_RDONLY);
	counter = 1;
	while((line = get_next_line(fd)) != NULL)
	{
		printf("Line %s", line);
		free(line);
	}
	close(fd);
	return (0);
}
