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
	printf("%i \n", fd1);
	printf("%i \n", fd2);
	printf("Line 1 FD 1: %s", get_next_line(fd1));
	printf("Line 1 FD 2: %s", get_next_line(fd2));
	printf("Line 2 FD 1: %s", get_next_line(fd1));
	printf("Line 2 FD 2: %s", get_next_line(fd2));
	// counter = 1;
	// while ((line = get_next_line(fd)) != NULL)
	// {
	// 	printf("Line %i : %s", counter++, line);
	// 	free(line);
	// }
	close(fd1);
	close(fd2);
	return (0);
}
