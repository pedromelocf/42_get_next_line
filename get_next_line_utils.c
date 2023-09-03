/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-ca <pmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:04:17 by pmelo-ca          #+#    #+#             */
/*   Updated: 2023/09/03 00:38:50 by pmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join_buf(char const *s1, char const *s2)
{
	char	*newstring;
	size_t	counter;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = strlen(s1);
	while(s2[s2_len] && s2[s2_len] != '\n')
		s2_len++;
	counter = 0;
	newstring = (char *)malloc(sizeof(char) * s1_len + s2_len);
	if (newstring == NULL)
		return (NULL);
	while (counter < s1_len + s2_len)
	{
		if (counter < s1_len)
			newstring[counter] = s1[counter];
		if (counter >= s1_len && counter < s1_len + s2_len)
			newstring[counter] = s2[counter - s1_len];
		counter++;
	}
	return (newstring);
}
char	*ft_new_line(char const *s1, char const *s2)
{
	char	*newstring;
	size_t	counter;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = strlen(s1);
	while(s2[s2_len] && s2[s2_len] != '\n')
		s2_len++;
	counter = 0;
	newstring = (char *)malloc(sizeof(char) * s1_len + s2_len + 2);
	if (newstring == NULL)
		return (NULL);
	while (counter < s1_len + s2_len)
	{
		if (counter < s1_len)
			newstring[counter] = s1[counter];
		if (counter >= s1_len && counter < s1_len + s2_len)
			newstring[counter] = s2[counter - s1_len];
		counter++;
	}
	newstring[counter] = '\n';
	newstring[counter + 1] = '\0';
	return (newstring);
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
