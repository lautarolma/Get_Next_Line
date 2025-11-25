/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 06:23:12 by laviles           #+#    #+#             */
/*   Updated: 2025/11/19 08:12:12 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char **s_buffer)
{
	char	*line;
	size_t	line_len;

	line_len = (ft_strchr(*s_buffer, '\n') - *s_buffer);
	write(1, "line_len = ", 11);
	write(1, &line_len, 1);
	line = ft_substr(*s_buffer, 0, line_len);
	return (line);
}

void	get_stash(char **s_buffer)
{
	size_t	stash_len;
	char	*ptr;
	char	*stash;
	
	ptr = ft_strchr(*s_buffer, '\n');
	if (!ptr)
		return;
	ptr++;
	stash_len = 0;
	while (ptr[stash_len] && ptr[stash_len] != '\n')
		stash_len++;
	write(1, "stash_len = ", 11);
	write(1, &stash_len, 1);
	stash = *s_buffer;
	*s_buffer = ft_substr(ptr, 0, stash_len);
	free(stash);
}

void	line_reader(int fd, char **s_buffer)
{
	char	*tmp;
	char	*buff;
	int		r_char;

	buff = (char *)ft_calloc((BUFFER_SIZE + 1), 1);
	r_char = read(fd, buff, BUFFER_SIZE);
	if (r_char == 0)
		return ;
	if (r_char < 0)
	{
		free(s_buffer);
		free(buff);
		write(1, "Read error", 10);
		return ;
	}
	buff[r_char] = '\0';
	tmp = *s_buffer;
	*s_buffer = ft_strjoin(tmp, buff);
	free(tmp);
	free(buff);
	buff = NULL;
}

char	*get_next_line(int fd)
{
	static char	*s_buffer[FD_LIMIT];
	char		*line;

	if (fd < 0 || fd >= FD_LIMIT || BUFFER_SIZE <= 0)
		return (NULL);
	if (!s_buffer[fd])
	{
		s_buffer[fd] = (char *)ft_calloc(1, 1);
		if (!s_buffer[fd])
			return (NULL);
	}
	while (!ft_strchr(s_buffer[fd], '\n'))
	{
		line_reader(fd, &s_buffer[fd]);
		if (s_buffer == NULL)
			return (NULL);
	}
	if (!ft_strchr(s_buffer[fd], '\n'))
		return (s_buffer[fd]);
	line = get_line(&s_buffer[fd]);
	if (!line)
		return (NULL);
	get_stash(&s_buffer[fd]);
	if (s_buffer == NULL)
		return (NULL);
	return (line);
}

int	main(void)
{
	int		fd = open("manguitaaa.txt", O_RDWR);
	char	*line;

	line = get_next_line(fd);
	printf("%s", line);
	return (0);
}
