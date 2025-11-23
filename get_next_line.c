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

char	*get_stash(char **s_buffer)
{
	char	*stash;
	size_t	stash_len;
	char	*ptr;
	
	ptr = ft_strchr(*s_buffer, '\n');
	stash_len = 0;
	while (ptr[stash_len])
		stash_len++;
	write(1, "stash_len = ", 11);
	write(1, &stash_len, 1);
	stash = ft_substr(ptr, 0, stash_len);
	return (stash);
}

char	*line_reader(int fd, char **s_buffer)
{
	char	*buff;
	int		r_char;

	if (fd < 0 || !**s_buffer || !*s_buffer)
		return (NULL);
	buff = (char *)ft_calloc((BUFFER_SIZE + 1), 1);
	r_char = read(fd, *s_buffer, BUFFER_SIZE);
	if (r_char == 0)
		return (NULL);
	if (r_char < 0)
	{
		free(s_buffer);
		free(buff);
		return (write(1, "Read error", 10), NULL);
	}
	*s_buffer[r_char] = '\0';
	*s_buffer = ft_strjoin(&*s_buffer, buff);
	free(buff);
	buff = NULL;
	return (*s_buffer);
}

char	*get_next_line(int fd)
{
	static char	**s_buffer;
	char		*line;

	if (!s_buffer)
	{
		*s_buffer = (char *)ft_calloc(1, 1);
		if (!*s_buffer)
				return (NULL);
	}
	while (!ft_strchr(*s_buffer, '\n'))
		line_reader(fd, &*s_buffer);
	line = get_line(&*s_buffer);
	get_stash(&*s_buffer);
	return (line);
}

int	main()
{
	int		fd = open("manguitaaa.txt", O_RDWR);
	char	*line;

	line = get_next_line(fd);
	printf("%s", line);
}
