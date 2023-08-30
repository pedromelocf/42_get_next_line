/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:04:19 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/08/30 17:05:17 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*next_line_content;
	char		*buf;
	char		*actual_line_content;
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next_line_content = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (ft_strchr(buf, '\n') == NULL)
	{
		buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		read(fd, buf, BUFFER_SIZE);
		strcat(actual_line_content, buf);
		new_line = ft_strchr(buf, '\n');
		if (new_line)
		{
			*new_line = '\0';
			memmove(next_line_content, new_line + 1, BUFFER_SIZE - (new_line - next_line_content) - 1);
			break ;
		}
		else
			buf = NULL;
	}
	return (buf);
}
