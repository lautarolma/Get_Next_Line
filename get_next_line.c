#include "get_next_line.h"

void	line_reader(int fd, char **rest_ln)
{
	char	*buff;
	int		chrs_read;
	int		i;
	char	*tmp;

	chrs_read = 1;
	buff = (char *)ft_calloc((BUFFER_SIZE + 1), 1);
	while (chrs_read > 0 && !ft_strchr(*rest_ln, '\n'))
	{
		i = 0;
		while (i < BUFFER_SIZE)
			buff[i++] = '\0';
		chrs_read = read(fd, buff, BUFFER_SIZE);
		buff[chrs_read] = '\0';
		write(1, buff, 43);
		tmp = *rest_ln;
		*rest_ln = ft_strjoin(*rest_ln, buff);
		free(tmp);
		tmp = NULL;
	}
	free(buff);
	buff = NULL;
}

char	*line_extract(char **rest_ln)//maybe I need to delete *dst
{
	char	*tmp;
	char	*line;
	size_t	i;

	i = 0;
	while (*rest_ln[i])
	{
		if (*rest_ln[i] == '\n')
			break;
		i++;
	}
	if (*rest_ln[i] == '\n')
		i++;	
//	write(1, &line_size, 1);
	line = ft_substr(*rest_ln, 0, i);
	tmp = *rest_ln;
	if (i != ft_strlen(*rest_ln))
		*rest_ln = ft_substr(*rest_ln, i, ft_strlen(*rest_ln));
	free(tmp);
	tmp = NULL;
	return (line);
}
/*
char	*rest_updater(char *rest_ln)
{
	char	*str;
	char	*eol;
	size_t	rest_size;

	eol = ft_strchr(rest_ln, '\n');
	rest_size = 0;
	while (rest_ln[rest_size])
		rest_size++;
	rest_size = (&rest_ln[rest_size] - eol);
	str = (char *)ft_calloc((rest_size + 1), 1);
	str[++rest_size] = '\0';
	return (str);
}
*/
char	*get_next_line(int fd)
{
	static char	*rest_ln;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!rest_ln)
		rest_ln = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
//	if (!ft_strchr(rest_ln, '\n'))Verificacion posiblemente innecesaria
//printf("Start GNL");
	line_reader(fd, &rest_ln);
//printf("After reader: %s", rest_ln);
//	write(1, rest_ln, 42);
//	line = (char *)ft_calloc(1, 1);
	line = line_extract(&rest_ln);
//printf("After extract: %s", rest_ln);
//	rest_ln = rest_updater(rest_ln);
	return (line);
}

int	main(void)
{
	int		fd;
	
	fd = open("manguitaaa.txt", O_RDWR);
	printf("%s", get_next_line(fd));
	return(0);
}
