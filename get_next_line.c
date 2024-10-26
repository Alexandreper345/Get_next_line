/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:51:24 by alda-sil          #+#    #+#             */
/*   Updated: 2024/10/25 19:56:07 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *joinfree(char *line,char *buffer)
{
	char	*temp;

	temp = ft_strjoin(line,buffer);
	free(line);
	return (temp);
}

#include <stdio.h>
char	*line_read(int fd,char *line)
{
	char	*buffer;
	int		byte_lead;
	char	*temp;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	byte_lead = 1;
	while (byte_lead > 0 && !ft_strchr(line, '\n'))
	{

		if (byte_lead < 0)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
				
		if (!line)
		{
			free(buffer);
			return (NULL);
		}
		if (byte_lead == -1)
			break;
		byte_lead = read(fd, buffer, BUFFER_SIZE);
		buffer[byte_lead] = '\0';
		temp = ft_strjoin(line,buffer);
		if (!temp)
		{
			free(line);
			free(buffer);
		}
		line = temp;
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	
	if (fd < 0)
		return (NULL);
	line = line_read(fd, line);
	if(!line)
		return (NULL);
	return(line);
}
