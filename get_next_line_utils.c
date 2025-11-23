/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 03:31:49 by laviles           #+#    #+#             */
/*   Updated: 2025/11/19 07:12:52 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nb, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(nb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < nb)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_strchr(char *s, int c)
{
	char	*c_c;

	if (!s)
		return (NULL);
	if ((unsigned char)c == '\0')
		return (s);
	c_c = (char *)s;
	while (*c_c)
	{
		if (*c_c == (unsigned char)c)
			return (c_c);
		c_c++;
	}
	return (NULL);
}

char	*ft_memcpy(char *dest, char *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*dst;
	size_t		i;
	size_t		slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_calloc(1, sizeof(char)));
	if (len > slen - start)
		len = (slen - start);
	dst = (char *)malloc(len + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[len] = '\0';
	return (dst);
}
/*
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !s2)
		return (NULL);
	len = 0;
	while (s1[len])
		len++;
	k = -1;
	while (s2[++k])
		len++;
	str = (char *)calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		c;
	int		i;

	c = 0;
	i = 0;
	s3 = (char *) malloc (ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	while (s1[c] != '\0')
	{
		s3[c] = s1[c];
		c++;
	}
	while (s2[i] != '\0')
	{
		s3[c + i] = s2[i];
		i++;
	}
	s3[c + i] = '\0';
	return (s3);
}

size_t	ft_strlen(const char *s)
{
	const char	*start;

	start = s;
	while (*start)
	{
		start++;
	}
	return (start - s);
}
