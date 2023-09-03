/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:04:19 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/09/03 00:33:46 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*next_line_content;
	char	*actual_line_content;
	char	*new_line;
	char	*buffer_read;

	actual_line_content = ft_strdup("");
	if (BUFFER_SIZE <= 0 || fd < 0)
		return(NULL);
	if (next_line_content != NULL)
	{
		actual_line_content = ft_join_buf(actual_line_content, next_line_content);
		new_line = ft_strchr(next_line_content, '\n');
		next_line_content = ft_strdup(new_line + 1);
	}
	while (ft_strchr(actual_line_content, '\n') == NULL)
	{
		buffer_read = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		if (read(fd, buffer_read, BUFFER_SIZE) <= 0)
		{
			if(ft_strchr(actual_line_content, '\0') == NULL)
				actual_line_content[strlen(actual_line_content)] = '\0';
			return (NULL);
		}
		if (ft_strchr(buffer_read, '\n') != NULL)
		{
			actual_line_content = ft_new_line(actual_line_content, buffer_read);
			new_line = ft_strchr(next_line_content, '\n');
			next_line_content = ft_strdup(new_line + 1);
			break;
		}
		if (ft_strchr(buffer_read, '\n') == NULL)
			actual_line_content = ft_join_buf(actual_line_content, buffer_read);
	}
	return (actual_line_content);
}
