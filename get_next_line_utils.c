/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 03:31:49 by laviles           #+#    #+#             */
/*   Updated: 2025/11/18 12:31:35 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	*gnl_calloc(size_t nb)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(nb)g;
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*my_memcpy(char *dest, char *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (dest)
		dest[i++];
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *current_line, char const *last_line_read)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len = 0;
	while (s1[len])
		len++;
	while (s2[len])
		len++;
	str = (char *)calloc((len), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
		str[i] = s1[i++];
	j = 0;
	while (s2[j])
		str[i + j] = s2[j++];
	str[i + j] = '\0';
	return (str);
}
