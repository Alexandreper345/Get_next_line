/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:51:59 by alda-sil          #+#    #+#             */
/*   Updated: 2024/10/24 20:21:01 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEX_LINE_H
# define GET_NEX_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42;
# endif
# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);

#endif