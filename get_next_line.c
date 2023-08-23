/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:04:19 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/08/23 14:29:56 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	actual_line[2000];
	char	temp_string_buffer[BUFFER_SIZE];
	size_t	read_buffer;

	read_buffer = read(fd, temp_string_buffer, BUFFER_SIZE);
	if (!(ft_strchr(temp_string_buffer, '\n')))
		strncat(actual_line, temp_string_buffer, read_buffer);
	else
		strncat(actual_line, temp_string_buffer, read_buffer);
	printf("Conteudo da variável temporária : %s\n\n", temp_string_buffer);
	printf("Conteudo da variável estática : %s\n\n", actual_line);
	printf("Tamanho de bytes lidos  : %ld\n\n", read_buffer);
	return (0);
}
