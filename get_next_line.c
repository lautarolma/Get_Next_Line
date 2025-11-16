/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laviles <laviles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 08:35:42 by laviles           #+#    #+#             */
/*   Updated: 2025/11/16 13:04:01 by laviles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_backup_line(char *buffer)
{
	
}

char	*get_next_line(int fd, )
{
	
}

char	*get_line(char *rest)
{
	char		*buffer;
	static char	*line_bkp;
	int			line_read;
	int			i;
	int			k;

	buffer = malloc((BUFFER_SIZE * sizeof(char)) + 1);
	if (!buffer)
		return (write(2, "Allocation error", 16), NULL);
	bytes_read = 0;
	while (bytes_read > 0) // Añadir o modificar la condicion. mientras que read no de error y que ¿?
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 1)
			return (NULL);
		k = 0;
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
				line_bkp[k++] = buffer[i + k];	
			buffer[i + 1] = '\0';
		}
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char *rest[1024]
char *line_read;
	char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 ||  BUFFER_SIZE < 1)
		return (NULL);

	if (!rest[fd])
		
	line_read = get_line()
	if (!lineread)
		return null
	//crear string que contega readline hasta nl
 	//asignar a static string el resto a partir de readline
	
1 Leer la línea en bucle hasta que lea nl
2 Crear un string que contenga lo de después del nl
3 O reutilizar la línea poniendo \0 o crear otro string para la linea
	return (line);
}
