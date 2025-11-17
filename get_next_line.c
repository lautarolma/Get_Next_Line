/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 06:23:12 by laviles           #+#    #+#             */
/*   Updated: 2025/11/17 17:34:05 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*found_newline(char *buff, int len)
{
	int		i;

	i = 0;
	while (i++ < len)
	{
		if (buff[i] == '\n')
			return (&buff[i]);
		else
			i++;
	}
	return (NULL);
}
char	*line_reader(static char *current_line, int	fd)
{
	int		chars_read
	char	*buff;
	char	*p;
	int		i;

	if (!current_line || fd < 0)
		return (NULL);
	buff = (char *)calloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (chars_read != EOF)
	{
		chars_read = read(fd, buff, BUFFER_SIZE);
		p = found_newline(buff, chars_read);
		if (!p)
			memcpy(current_line, buff, chars_read);	
		else
			ft_strjoin(current_line, chars_read);
	}
	return (current_line);
}

char	*get_next_line(int fd)
{
	static char	**current_line;
	int			*array[FD_LIMIT];
	char		*buff_reader[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buff_reader, 0) < 0)
		return (NULL);
	*current_line = NULL;
	while (array[fd] != EOF)
		current_line[i] = line_reader(array[fd])
	
}
