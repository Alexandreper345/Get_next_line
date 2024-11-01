/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:51:49 by alda-sil          #+#    #+#             */
/*   Updated: 2024/11/01 16:08:56 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	num;
	int i;

	num = 0;
	i = 0;
	while (str[i])
	{
		i++;
		num++;
	}
	return (num);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*vec;

	i = 0;
	vec = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (s[i])
	{
		vec[i] = s[i];
		i++;
	}
	vec[i] = '\0';
	return (vec);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*vec;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	vec = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!vec)
		return (NULL);
	while (s1[i])
	{
		vec[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		vec[i] = s2[j];
		j++;
		i++;
	}
	vec[i] = '\0';
	if (!vec)
		free(vec);
	return (vec);
}



