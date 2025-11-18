/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 06:23:12 by laviles           #+#    #+#             */
/*   Updated: 2025/11/18 12:31:32 by laviles          ###   ########.fr       */
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
char	*line_reader(char *current_line, int fd)
{
	int		chars_read
	char	*buff;
	int		i;

	if (!current_line || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)gnl_calloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	chars_read = read(fd, buff, BUFFER_SIZE);
	if (chars_read =< 0)
		return (NULL);
	buff[chars_read] = '\0';
	return (buff);
}

char	*get_next_line(int fd)
{
	static char *rest[fd];
	char		*current_line;
	char		*end_of_line;

	if (fd < 0 || read(fd, buff_reader, 0) < 0) //chequear si el control de permisos en read es correcto.
		return (NULL);
	*current_line = line_reader(fd);
	end_of_line = find_end_line(current_line);
	while (!end_of_line)
		gnl_strjoin(current_line, line_reader(fd));
	if (end_of_line)
		gnl_memcpy(lastline_rest, end_of_line);
	return (current_line);
}
