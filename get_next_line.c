/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:04:19 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/08/23 19:29:25 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	actual_line[2000];
	char	*temp_string_buffer;
	size_t	read_buffer;

	read_buffer = read(fd, actual_line, BUFFER_SIZE);
	temp_string_buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!(ft_strchr(actual_line, '\n')))
		strncat(temp_string_buffer, actual_line, read_buffer);
	if (ft_strchr(actual_line, '\n'))
		strncat(temp_string_buffer, actual_line, read_buffer);
	return (temp_string_buffer);
}
