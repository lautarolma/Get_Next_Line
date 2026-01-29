/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 08:41:31 by laviles           #+#    #+#             */
/*   Updated: 2025/11/27 17:19:04 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define FD_LIMIT 1024

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int		line_reader(int fd, char **s_buffer);
char	*extract_line(char **s_buffer);
void	get_stash(char **s_buffer);
void	*gnl_ft_calloc(size_t nmemb, size_t size);
size_t	gnl_ft_strlen(char *s);
char	*gnl_ft_substr(char *s, unsigned int start, size_t len);
char	*gnl_ft_strjoin(char *s_buffer, char *buff);
char	*gnl_ft_strchr(const char *s, int c);

#endif
