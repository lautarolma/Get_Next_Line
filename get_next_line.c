/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 06:23:12 by laviles           #+#    #+#             */
/*   Updated: 2025/11/17 10:06:36 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	found_newline(char *buff, int len)
{
	while (i++ < len)
		if (buff[i++] != '\n')
			
}
char	*line_reader(static char *current_line, int	fd)
{
	int		lines_read
	char	*buff;
	int		i;

	if (!current_line || fd < 0)
		return (NULL);
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (lines_read != EOF)
	{
		lines_read = read(fd, buff, BUFFER_SIZE);
		while (!found_newline(buff, lines_read))
		{
			buff[i]
		}
			
	}
	
}

char	*get_next_line(int fd)
{
	static char	**current_line;
	int			*array[FD_LIMIT];
	char		*buff_reader[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buff_reader, 0) < 0)
		return (NULL);
	current_line = NULL;
	while (array[fd] != EOF)
		current_line[i] = line_reader(array[fd])
	
}
