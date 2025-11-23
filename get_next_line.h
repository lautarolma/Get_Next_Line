/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 08:41:31 by laviles           #+#    #+#             */
/*   Updated: 2025/11/19 05:59:15 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define FD_LIMIT 1024

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s);
char    *ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_memcpy(char *dest, char *src, size_t n);
char	*ft_strchr(char *s, int c);
void	*ft_calloc(size_t nb, size_t size);
char	*get_next_line(int fd);
char	*line_extract(char **rest_ln);
void	line_reader(int fd, char **rest_ln);

#endif
