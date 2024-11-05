/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:51:24 by alda-sil          #+#    #+#             */
/*   Updated: 2024/11/04 21:15:05 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*save_backup(char *c)
{
	char	*backup;
	char	*newline;

	if (*c == '\0')
		return (0);
	newline = ft_strchr(c, '\n');
	if (!newline)
		return (0);
	backup = ft_strdup(newline + 1);
	newline++;
	*newline = '\0';
	return (backup);
}

char	*line_read(int fd, char *line)
{
	char	*buffer;
	int		byte_lead;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	byte_lead = 1;
	while (byte_lead > 0)
	{
		byte_lead = read(fd, buffer, BUFFER_SIZE);
		if (byte_lead == -1)
		{
			free(buffer);
			free(line);
			return (0);
		}
		else if (byte_lead == 0)
			break ;
		buffer[byte_lead] = '\0';
		if (!line)
			line = ft_strdup("");
		line = ft_strjoin(line, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*backup = NULL;
	char		*current_line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	current_line = line_read(fd, backup);
	if (!current_line)
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	backup = save_backup(current_line);
	return (current_line);
}
