/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:51:24 by alda-sil          #+#    #+#             */
/*   Updated: 2024/11/01 18:00:43 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


char	*save_backup(char *c)
{
	char	*backup;
	char	*newline;

	newline = ft_strchr(c,'\n');
	backup = ft_strdup(newline + 1);
	if (!backup)
	{
		free(c);
		return (NULL);
	}
	newline++;
	*newline = '\0';
	return (backup);
}

char	*line_read(int fd,char *line)
{
	char	*buffer;
	int		byte_lead;
	
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return(NULL);
	byte_lead = 1;
	while (byte_lead > 0)
	{
		byte_lead = read(fd, buffer, BUFFER_SIZE);
		if (byte_lead == -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		if (byte_lead == 0)
			return (NULL);
		buffer[byte_lead] = '\0';
		if (!line)
			line = ft_strdup("");
		line = ft_strjoin(line, buffer);
		if (ft_strchr(buffer,'\n'))
			break;
		if (byte_lead == '\0')
			return (NULL);
	}
	free(buffer);  
	return(line);
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char	*s;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	s = line_read(fd, line);
	if(!s)
		s = line;
	line = save_backup(s);
	return(s);
}
