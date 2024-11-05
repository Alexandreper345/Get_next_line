/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:51:24 by alda-sil          #+#    #+#             */
/*   Updated: 2024/11/05 18:46:49 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*save_backup(char *c)
{
	char	*backup;
	char	*newline;

	if (*c == '\0' || c == NULL)
		return (NULL);
	newline = ft_strchr(c, '\n');
	if (!newline)
		return (NULL);
	backup = ft_strdup(newline + 1);
	if (*backup == '\0')
	{
		free(backup);
		backup = NULL;
	}
	newline++;
	*newline = '\0';
	return (backup);
}

char	*line_read(int fd, char *buffer, char *line)
{
	int		byte_lead;

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
		else if (byte_lead == 0)
			break ;
		if (!line)
			line = ft_strdup("");
		buffer[byte_lead] = '\0';
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
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	current_line = line_read(fd, buffer, backup);
	if (!current_line)
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	backup = save_backup(current_line);
	return (current_line);
}
