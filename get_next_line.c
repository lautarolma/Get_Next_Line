/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 06:23:12 by laviles           #+#    #+#             */
/*   Updated: 2025/11/26 01:20:18 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char **s_buffer)
{
	char	*line;
	size_t	line_len;
	char	*ptr;

	ptr = ft_strchr(*s_buffer, '\n');
	if (ptr)
		line_len = (ptr - *s_buffer) + 1;
	else
		line_len = ft_strlen(s_buffer);//Aqui get_line retorno la ultima linea, ergo get_ stash no debe retornar, sino liberar el buffery el puntero.
	if (line_len == 0)
		return (NULL);
	line = ft_substr(*s_buffer, 0, line_len);
	return (line);
}

void	get_stash(char **s_buffer)
{
	size_t	stash_len;
	char	*ptr;
	char	*stash;
	
	ptr = ft_strchr(*s_buffer, '\n');
	if (!ptr)//aqui si se cumple, es que se acabo el file, he de finalizar y liberar la memoria en uso del programa
	{
		free(*s_buffer);
		*s_buffer = NULL;
		return;
	}
	ptr++;
	stash_len = 0;
	while (ptr[stash_len] && ptr[stash_len] != '\n')
		stash_len++;
	stash = ft_substr(ptr, 0, stash_len);
	free(*s_buffer);
	*s_buffer = stash;
}

void	line_reader(int fd, char **s_buffer, int *eol)
{
	char	*buff;
	int		r_char;

	buff = (char *)ft_calloc((BUFFER_SIZE + 1), 1);
	r_char = read(fd, buff, BUFFER_SIZE);
	if (r_char == 0)
		*eol = 1;
	}
	if (r_char < 0)
	{
		free(s_buffer);
		free(buff);
		write(1, "Read error", 10);
		return ;
	}
	buff[r_char] = '\0';
	*s_buffer = ft_strjoin(*s_buffer, buff);
	free(buff);
	buff = NULL;
}

char	*get_next_line(int fd)
{
	static char	*s_buffer[FD_LIMIT];
	char		*line;
	int			*eol;

	if (fd < 0 || fd >= FD_LIMIT || BUFFER_SIZE <= 0)
		return (NULL);
	if (!s_buffer[fd])
	{
		s_buffer[fd] = (char *)ft_calloc(1, 1);
		if (!s_buffer[fd])
			return (NULL);
	}
	eol = 0;
	while (!ft_strchr(s_buffer[fd], '\n') && eol != 1)
	{
		line_reader(fd, &s_buffer[fd], &eol);
		if (!s_buffer[fd])
			return (NULL);
	}
	if (!ft_strchr(s_buffer[fd], '\n'))
		return (s_buffer[fd]);
	line = get_line(&s_buffer[fd]);
	if (!line)
		return (free(s_buffer[fd]), NULL);
	get_stash(&s_buffer[fd]);
	if (!s_buffer[fd])
		return (free(s_buffer[fd]), NULL);
	return (line);
}

int	main(void)
{
	int		fd = open("manguitaaa.txt", O_RDWR);
	char	*line;

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
