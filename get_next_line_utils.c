/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 03:31:49 by laviles           #+#    #+#             */
/*   Updated: 2025/11/17 10:09:37 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	*ft_calloc(size_t nb)
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
