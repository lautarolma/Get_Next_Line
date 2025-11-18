/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 03:31:49 by laviles           #+#    #+#             */
/*   Updated: 2025/11/18 20:45:28 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*gnl_calloc(size_t nb)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(nb);
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

char	*my_memcpy(char *dest, char *src, size_t n)
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

char	*ft_strjoin(char const *current_line, char const *buff)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!current_line || !buff)
		return (NULL);
	len = 0;
	while (current_line[len])
		len++;
	while (buff[len])
		len++;
	str = (char *)calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (current_line[i])
		str[i] = current_line[i++];
	j = 0;
	while (buff[j])
		str[i + j] = buff[j++];
	str[i + j] = '\0';
	return (str);
}
