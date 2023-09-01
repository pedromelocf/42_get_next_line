/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:04:19 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/09/01 14:42:40 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*verify_read(int fd, char *actual_line_content);
char	*verify_new_line(char *new_line, char *next_line_content,
			char *verified_buffer);

char	*get_next_line(int fd)
{
	static char	*next_line_content;
	char		*actual_line_content;
	char		*new_line;
	char		*verified_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	actual_line_content = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (next_line_content != NULL)
	{
		actual_line_content = ft_strdup(next_line_content);
		free(next_line_content);
	}
	while (ft_strchr(actual_line_content, '\n') == NULL)
	{
		verified_buffer = verify_read(fd, actual_line_content);
		if (verified_buffer == NULL)
			return (NULL);
		actual_line_content = ft_strjoin(actual_line_content, verified_buffer);
		new_line = ft_strchr(verified_buffer, '\n');
		if (new_line)
		{
			next_line_content = verify_new_line(new_line, next_line_content,
					verified_buffer);
			break ;
		}
		else
			free(verified_buffer);
	}
	return (actual_line_content);
}

char	*verify_new_line(char *new_line, char *next_line_content,
		char *verified_buffer)
{
	*new_line = '\0';
	next_line_content = ft_strdup(new_line + 1);
	free(verified_buffer);
	return (next_line_content);
}

char	*verify_read(int fd, char *actual_line_content)
{
	char	*buf;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (read(fd, buf, BUFFER_SIZE) <= 0)
	{
		free(buf);
		free(actual_line_content);
		return (NULL);
	}
	return (buf);
}
