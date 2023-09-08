/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:04:19 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/09/08 14:28:47 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read_fd(int fd, char *total_buffer);
char* ft_cut_buffer(char *total_buffer);

char *ft_read_fd(int fd, char *total_buffer)
{
	char *buffer_read;
	size_t bytes_read;

	buffer_read = malloc(sizeof(char) * BUFFER_SIZE + 1);
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
		total_buffer = ft_join_buf(total_buffer, buffer_read);
	}
	free(buffer_read);
	return(total_buffer);
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

char	*get_next_line(int fd)
{
	static char *total_buffer;
	char	*actual_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (total_buffer == NULL)
		total_buffer = ft_strdup("");
	total_buffer = ft_read_fd(fd, total_buffer);
	if(total_buffer == NULL)
		return(NULL);
	actual_line = ft_strdup("");
	actual_line = ft_new_line(actual_line, total_buffer);
	total_buffer = ft_cut_buffer(total_buffer);
	return (actual_line);
}
