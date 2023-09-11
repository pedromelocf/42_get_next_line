#include "get_next_line_bonus.h"

static char *ft_read_fd(int fd, char *total_buffer);
static char	*ft_new_line(char const *total_buffer);
static char *ft_cut_buffer(char *total_buffer);

char	*get_next_line(int fd)
{
	static char *total_buffer[1024];
	char	*actual_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	total_buffer[fd] = ft_read_fd(fd, total_buffer[fd]);
	if(total_buffer[fd] == NULL)
		return(NULL);
	actual_line = ft_new_line(total_buffer[fd]);
	total_buffer[fd] = ft_cut_buffer(total_buffer[fd]);
	return (actual_line);
}

char *ft_read_fd(int fd, char *total_buffer)
{
	char *buffer_read;
	size_t bytes_read;

	buffer_read = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer_read == NULL)
		return (NULL);
	bytes_read = 1;
	while (!(ft_strchr(total_buffer, '\n')) && (bytes_read != 0))
	{
		bytes_read = read(fd, buffer_read, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer_read);
			free(total_buffer);
			return(NULL);
		}
		buffer_read[bytes_read] = '\0';
		total_buffer = ft_join_buf(total_buffer, buffer_read);
	}
	free(buffer_read);
	return(total_buffer);
}

char	*ft_new_line(char const *total_buffer)
{
	char	*newstring;
	size_t	counter;
	size_t	s1_len;

	if (!total_buffer)
		return (NULL);
	counter = 0;
	s1_len = 0;
	while (total_buffer[s1_len] != '\n' && total_buffer[s1_len] != '\0')
		s1_len++;
	newstring = (char *)malloc(sizeof(char) * s1_len + 2);
	if (newstring == NULL)
		return (NULL);
	while (counter < s1_len)
	{
		newstring[counter] = total_buffer[counter];
		counter++;
	}
	newstring[s1_len] = '\n';
	newstring[s1_len + 1] = '\0';
	return (newstring);
}

char* ft_cut_buffer(char *total_buffer)
{
	int i;
	int j;
	char *temp;

	i = 0;
	while (total_buffer[i] && total_buffer[i] != '\n')
		i++;
	if (!total_buffer[i])
	{
		free(total_buffer);
		return(NULL);
	}
	temp = (char *)malloc(sizeof(char) * (strlen(total_buffer) - i + 1));
	if (!temp)
		return(NULL);
	i++;
	j = 0;
	while (total_buffer[i])
		temp[j++] = total_buffer[i++];
	temp[j] = '\0';
	free(total_buffer);
	return(temp);
}