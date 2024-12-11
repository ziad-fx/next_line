/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:43:59 by zyahansa          #+#    #+#             */
/*   Updated: 2024/12/10 18:35:35 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

void	efh_helper(char **homie, char **line, int *i)
{
	if ((*homie)[*i] == '\n')
	{
		*line = malloc(*i + 2);
		if (!*line)
			return ;
		ft_strncpy(*line, *homie, *i + 1);
		(*line)[*i + 1] = '\0';
	}
	else
	{
		*line = malloc(*i + 1);
		if (!*line)
			return ;
		ft_strncpy(*line, *homie, *i);
		(*line)[*i] = '\0';
	}
}

char	*extr_f_homie(char **homie)
{
	int		i;
	char	*line;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while ((*homie)[i] && (*homie)[i] != '\n')
		i++;
	if ((*homie)[i] == '\n')
	{
		efh_helper(homie, &line, &i);
		tmp = ft_strdup(*homie + i + 1);
		if (!tmp)
			return (NULL);
	}
	else
	{
		efh_helper(homie, &line, &i);
		if (!line)
			return (NULL);
		tmp = NULL;
	}
	return (free(*homie), *homie = tmp, line);
}

char	*gnl_helper(int fd, char *homie)
{
	int		c_bytes;
	char	*buffer;

	c_bytes = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (free(homie), homie = NULL, NULL);
	while (c_bytes > 0)
	{
		c_bytes = read(fd, buffer, BUFFER_SIZE);
		if (c_bytes < 0)
			return (free(buffer), buffer = NULL, NULL);
		if (c_bytes == 0)
			break ;
		buffer[c_bytes] = '\0';
		homie = ft_strjoin(homie, buffer);
		if (!homie)
			return (free(buffer), buffer = NULL, NULL);
		if (ft_strchr(homie, '\n'))
			break ;
	}
	free(buffer);
	return (homie);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*homie;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0
		|| BUFFER_SIZE > INT_MAX)
		return (free(homie), homie = NULL, NULL);
	homie = gnl_helper(fd, homie);
	if (!homie || *homie == '\0')
		return (free(homie), homie = NULL, NULL);
	line = extr_f_homie(&homie);
	if (!line)
		return (free(line), NULL);
	return (line);
}

int main()
{
	int fd;
	// fd = open("file.txt", O_RDWR);
	// int fd1 = open("file1.txt", O_RDWR);
	// char *tmp = get_next_line(fd);
	// while (tmp)
	// {
	// 	write(fd1, tmp, ft_strlen(tmp));
	// 	free(tmp);
	// 	tmp = get_next_line(fd);
	// }
	// close(fd);
	fd = open("file.txt", O_RDWR);
	char *tmp1 = get_next_line(fd);
	while (tmp1)
	{
		printf("line:%s", tmp1);
		free(tmp1);
		tmp1 = get_next_line(fd);
	}
	close(fd);
	// close(fd1);
}
