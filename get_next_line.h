/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:24:56 by zyahansa          #+#    #+#             */
/*   Updated: 2024/12/07 19:59:58 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <string.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char	*s1, char *s2);
size_t	ft_strlen(const char *s);
char	*extr_f_homie(char **homie);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);

#endif