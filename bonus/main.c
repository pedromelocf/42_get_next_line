#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char		*line;
	int			fd1;
	int 		fd2;
	int			counter;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	counter = 1;
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("Line %i : %s", counter++, line);
		free(line);
	}
	counter = 1;
	while ((line = get_next_line(fd2)) != NULL)
	{
		printf("Line %i : %s", counter++, line);
		free(line);
	}
	close(fd1);
	close(fd2);
	return (0);
}
