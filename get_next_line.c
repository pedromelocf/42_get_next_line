/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:04:19 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/08/23 11:50:48 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*actual_line[3000];
	char	temp_string_buffer[BUFFER_SIZE];
	size_t	read_buffer;

	read_buffer = read(fd, temp_string_buffer, BUFFER_SIZE);

	if (!(ft_strchr(temp_string_buffer, '\n')))
		actual_line[0] = ft_substr(temp_string_buffer, 0, BUFFER_SIZE);
	// printf("Conteudo da variável temporária : %s\n", temp_string_buffer);
	// printf("Conteudo da variável estática : %s\n", actual_line[0]);
	// printf("Tamanho de bytes lidos  : %ld\n\n", read_buffer);
	return (0);
}
