/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 06:23:12 by laviles           #+#    #+#             */
/*   Updated: 2025/11/18 20:48:57 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*find_end_line(char *buff)
{
	int		i;

	if (!buff)
		return (NULL);
	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (&buff[i]);
		else
			i++;
	}
	return (NULL);
}

char	*line_reader(int fd, char *buff, char check)
{
	int		chars_read
	int		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)gnl_calloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	chars_read = read(fd, buff, BUFFER_SIZE);
	if (chars_read =< 0)
		return (NULL);
	buff[chars_read] = '\0';
	if (buff < BUFF_SZ)
		check = 1;
	return (buff);
}

char	*get_next_line(int fd)
{
	static char		*lastline_rest[FD_LIMIT];
	char			*current_line;
	char			*end_of_line;
	char			check;		
	char			*buff;

	if (fd < 0)
		return (NULL);
	lastline_rest[fd] = (char *)gnl_calloc(BUFFER_SIZE + 1);
	if (*lastline_rest != NULL && !find_end_line(current_line))
		current_line = line_reader(fd, buff, check);
	end_of_line = find_end_line(current_line);
	while (!end_of_line)
	{
		current_line = gnl_strjoin(current_line, line_reader(fd));
		end_of_line = find_end_line(current_line);
	}
	gnl_memcpy(lastline_rest, end_of_line);
	if (check == 1)
		free(lastline_rest);
	return (current_line);
}

//current_line y buffer, deberian ser la misma variable, al parecer. Paco me hizo un analicis de errores que deberia de revisar. 
