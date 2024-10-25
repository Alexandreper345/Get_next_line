/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:51:24 by alda-sil          #+#    #+#             */
/*   Updated: 2024/10/25 16:58:18 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*joinfree(char *line, char *str)
{
	char	*temp;

	temp = ft_strjoin(line, str);
	free(line);
	return(temp);
}

/*
char	get_last_line(char *line)
{
	char	*last_line;
	char	*new_line;

	new_line = '\0';
	last_line = ft_strdup(line);
	return (last_line);
}
*/

static char *read_f(char *line, int fd)
{
	char	*str;
	int		byte_lead;

	byte_lead = 1;
	str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	while (byte_lead > 0)
	{
		byte_lead = read(fd,str,BUFFER_SIZE);
		if (byte_lead < 0)
		{
			free(str);
			return (NULL);
		}
		str[byte_lead] = '\0';
		free(line);
		line = joinfree(line, str);
		if(ft_strchr(line, '\n'))
			break;	
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	//char	*nextline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	else
		read_f(line,fd);
	return(line);	
}
