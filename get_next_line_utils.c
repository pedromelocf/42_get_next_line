/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:04:17 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/08/29 10:32:07 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = strlen(s);
	while (i <= s_len)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*newstring;
	size_t	index1;
	size_t	index2;

	index1 = 0;
	index2 = 0;
	while (s[index1])
		index1++;
	newstring = (char *)malloc(sizeof(char) * index1 + 1);
	if (!newstring)
		return (NULL);
	while (index2 < index1)
	{
		newstring[index2] = s[index2];
		index2++;
	}
	newstring[index2] = '\0';
	return (newstring);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		counter;
	char		*ptrdest;
	const char	*ptrsrc;

	counter = 0;
	ptrdest = dest;
	ptrsrc = src;
	if (ptrdest == NULL && ptrsrc == NULL)
		return (NULL);
	while (counter < n)
	{
		ptrdest[counter] = ptrsrc[counter];
		counter++;
	}
	return (dest);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array;
	size_t	index;
	size_t	maxint_validator;

	index = 0;
	maxint_validator = (nmemb * size);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (maxint_validator / nmemb != size)
		return (NULL);
	array = (void *)malloc(size * nmemb);
	if (array == NULL)
		return (NULL);
	while (index < nmemb * size)
	{
		array[index] = '\0';
		index++;
	}
	return (array);
}
