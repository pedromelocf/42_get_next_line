/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:04:19 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/08/23 11:03:22 by pmelo-ca         ###   ########.fr       */
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

	printf("Conteudo do arquivo : %s\n", temp_string_buffer);
	printf("Conteudo do arquivo : %ld\n\n", read_buffer);
	return (0);
}
