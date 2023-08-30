/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:04:19 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/08/29 20:02:02 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*static_array;
	char	*temp_array;
	char	*newline;

	if(fd < 0 || BUFFER_SIZE <=0)
		return (NULL);
	temp_array = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	temp_array[0] = '\0';
	while(ft_strchr(temp_array, '\n') == NULL)
	{
		printf("Static:\n%s\n", static_array);
		if (static_array == NULL)
		{
			static_array = (char*)malloc(sizeof(char) * BUFFER_SIZE);
			read(fd, static_array, BUFFER_SIZE);
			printf("Static read:\n%s\n", static_array);
		}
		newline = ft_strchr(static_array, '\n');
		if(newline)
		{
			printf("Test =\n");
			*newline = '\0';
			strcat(temp_array, static_array);
			printf("Static test:%s\n", static_array);
			memmove(static_array, newline + 1, BUFFER_SIZE - (newline - static_array) - 1);
			printf("Static test2:\n%s\n", static_array);
			break;
		}
		else
		{
			printf("Test ! \n");
			strcat(temp_array, static_array);
			static_array = NULL;
			printf("Static:\n%s\n", static_array);
		}
	}
	return (temp_array);
}
