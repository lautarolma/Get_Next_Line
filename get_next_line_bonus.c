/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 06:23:12 by laviles           #+#    #+#             */
/*   Updated: 2025/11/27 19:26:23 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*extract_line(char **s_buffer)
{
	char	*line;
	size_t	line_len;
	char	*ptr;

	ptr = gnl_ft_strchr(*s_buffer, '\n');
	if (ptr)
		line_len = (ptr - *s_buffer) + 1;
	else
		line_len = gnl_ft_strlen(*s_buffer);
	if (line_len == 0)
		return (NULL);
	line = gnl_ft_substr(*s_buffer, 0, line_len);
	return (line);
}

void	get_stash(char **s_buffer)
{
	size_t	stash_len;
	char	*ptr;
	char	*stash;

	ptr = gnl_ft_strchr(*s_buffer, '\n');
	if (!ptr || !*(ptr + 1))
	{
		free(*s_buffer);
		*s_buffer = NULL;
		return ;
	}
	ptr++;
	stash_len = gnl_ft_strlen(ptr);
	stash = gnl_ft_substr(ptr, 0, stash_len);
	free(*s_buffer);
	*s_buffer = stash;
}

int	line_reader(int fd, char **s_buffer)
{
	char	*buff;
	int		r_char;

	buff = (char *)gnl_ft_calloc((BUFFER_SIZE + 1), 1);
	if (!buff)
		return (-1);
	r_char = read(fd, buff, BUFFER_SIZE);
	if (r_char <= 0)
	{
		free(buff);
		if (r_char < 0 && *s_buffer)
		{
			free(*s_buffer);
			*s_buffer = NULL;
		}
		return (r_char);
	}
	buff[r_char] = '\0';
	*s_buffer = gnl_ft_strjoin(*s_buffer, buff);
	free(buff);
	buff = NULL;
	if (!*s_buffer)
		return (-1);
	return (r_char);
}

char	*get_next_line(int fd)
{
	static char	*s_buffer[FD_LIMIT];
	char		*line;
	int			read_status;

	if (fd < 0 || fd >= FD_LIMIT || BUFFER_SIZE <= 0)
		return (NULL);
	if (!s_buffer[fd])
		s_buffer[fd] = (char *)gnl_ft_calloc(1, 1);
	if (!s_buffer[fd])
		return (NULL);
	read_status = 1;
	while (!gnl_ft_strchr(s_buffer[fd], '\n') && read_status > 0)
		read_status = line_reader(fd, &s_buffer[fd]);
	if (read_status < 0 || !s_buffer[fd] || !*s_buffer[fd])
	{
		free(s_buffer[fd]);
		s_buffer[fd] = NULL;
		return (NULL);
	}
	line = extract_line(&s_buffer[fd]);
	if (!line)
		return (free(s_buffer[fd]), s_buffer[fd] = NULL, NULL);
	get_stash(&s_buffer[fd]);
	return (line);
}
/*
int	main(void)
{
	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
		return (printf("Error abriendo archivos\n"), 1);
	
	printf("FD1: %s", line = get_next_line(fd1));
	free(line);
	printf("FD2: %s", line = get_next_line(fd2));
	free(line);
	printf("FD3: %s", line = get_next_line(fd3));
	free(line);
	printf("FD1: %s", line = get_next_line(fd1));
	free(line);
	printf("FD2: %s", line = get_next_line(fd2));
	free(line);
	printf("FD3: %s", line = get_next_line(fd3));
	free(line);
	
	close(fd1);
	close(fd2);
	close(fd3);
}*/
