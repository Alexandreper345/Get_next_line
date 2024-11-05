/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:18:30 by alda-sil          #+#    #+#             */
/*   Updated: 2024/11/05 18:46:36 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	int		lines;
	char	*line;

	lines = 1;
	fd = open("testo.txt", O_RDWR);
	line = get_next_line(fd);
	while (line)
	{
		printf("linha: %s", line);
		free(line);
	}
	close(fd);
	return (0);
}
