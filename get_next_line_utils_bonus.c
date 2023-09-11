#include "get_next_line_bonus.h"

char	*ft_join_buf(char const *s1, char const *s2)
{
	char	*newstring;
	size_t	counter;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	counter = 0;
	newstring = (char *)malloc(sizeof(char) * s1_len + s2_len + 1);
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
	newstring[counter] = '\0';
	free((char *)s1);
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

	if (s == NULL)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	while (i < s_len)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int	counter;

	counter = 0;
	while (s[counter])
		counter++;
	return (counter);
}
