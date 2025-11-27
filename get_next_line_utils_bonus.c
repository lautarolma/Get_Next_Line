/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 03:31:49 by laviles           #+#    #+#             */
/*   Updated: 2025/11/27 03:41:01 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
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

char	*ft_strjoin(char *s_buffer, char *buff)
{
	char	*str;
	size_t	total_len;
	size_t	i;
	size_t	j;

	if (!s_buffer || !buff)
		return (NULL);
	total_len = ft_strlen(s_buffer) + ft_strlen(buff);
	str = (char *)ft_calloc((total_len + 1), sizeof(char));
	if (!str)
	{
		free(s_buffer);
		return (NULL);
	}
	i = -1;
	while (s_buffer[++i])
		str[i] = s_buffer[i];
	j = -1;
	while (buff[++j])
		str[i + j] = buff[j];
	str[i + j] = '\0';
	free(s_buffer);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char			*char_s;
	unsigned char	uchar_c;

	if (!s)
		return (NULL);
	char_s = (char *)s;
	uchar_c = (unsigned char)c;
	while (*char_s)
	{
		if (*char_s == uchar_c)
			return (char_s);
		char_s++;
	}
	if (uchar_c == 0)
		return (char_s);
	return (NULL);
}
