/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:04:19 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/08/22 13:04:56 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*file_content;
	char		*line;
	size_t 		test;

	test = 5;
	file_content = read(fd, BUFFER_SIZE, 100);
	line = ft_strlcpy(line, file_content, test);
	line[BUFFER_SIZE] = '\0';
	printf("Conteudo do arquivo : %s", line);
	return (line);
}
