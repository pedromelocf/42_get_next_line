/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:04:19 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/08/29 10:51:21 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*static_array;
	char	*temp_array;
	size_t buffer;

	if (!(static_array))
		static_array = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	buffer = read(fd, static_array, BUFFER_SIZE);
	while(buffer != 0)
	{
		printf("Static : %s\n", static_array);
		printf("Buffer: %zu\n", buffer);
		if(ft_strchr(static_array, '\n') == NULL)
		{
			strcat(temp_array, static_array);
			printf("Static : %s\n", static_array);
			printf("Temp : %s\n\n", temp_array);
			static_array = ft_calloc(BUFFER_SIZE, 1);
			buffer = read(fd, static_array, BUFFER_SIZE);
		}
		if(ft_strchr(static_array, '\n') != NULL)
			return (temp_array);
	}
	return (temp_array);
}
