/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:51:24 by alda-sil          #+#    #+#             */
/*   Updated: 2024/11/01 15:53:49 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


char	*save_backup(char *c)
{
	char	*backup;
	char	*newline;

	newline = ft_strchr(c,'\n');
	if (!newline)
	{
		return (NULL);
	}
	backup = ft_strdup(newline + 1);
	if (!backup)
	{
		free(c);
		return (NULL);
	}
	*newline = '\0';
	return (backup);
}

char	*line_read(int fd,char *line)
{
	char	*buffer;
	int		byte_lead;
	char	*temp;
	
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return(NULL);
	byte_lead = 1;
	while (byte_lead > 0)
	{
		byte_lead = read(fd, buffer, BUFFER_SIZE);
		if (byte_lead < 0)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		buffer[byte_lead] = '\0';
		if (!line)
			line = ft_strdup("");
		temp = ft_strjoin(line,buffer);
		free(line);
		line = temp;
		if(line == NULL)
		{
			free(buffer);
			return (NULL);
		}
		if (ft_strchr(buffer,'\n'))
			break;
	}
	free(buffer);

	if (byte_lead == 0 && line[0] == '\0')
	{
		free(line);
		return(NULL);
	}
	return(line);
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char	*s;

	if (fd < 0)
		return (NULL);
	s = line_read(fd, line);
	if(!s)
		return (NULL);
	line = save_backup(s);
	return(s);
}
