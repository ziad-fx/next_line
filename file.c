/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:29:55 by zyahansa          #+#    #+#             */
/*   Updated: 2024/12/10 11:03:38 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    int c_bytes;
    char *buffer;
    char *line;
    static char *homie;
    if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        free(homie);
        homie = NULL;
        return (NULL);
    }
    c_bytes = 1;
    buffer = malloc(BUFFER_SIZE + 1);
    if(buffer == NULL)
        return (free(homie), homie = NULL, NULL);
    while (c_bytes > 0)
    {
        c_bytes = read(fd, buffer, BUFFER_SIZE);
        if (c_bytes < 0)
            return (free(buffer), buffer = NULL, NULL);
        if (c_bytes == 0)
            break;
        buffer[c_bytes] = '\0';
        homie = ft_strjoin(homie, buffer);
        if (!homie)
            return (free(buffer), buffer = NULL, NULL);
        if (ft_strchr(homie, '\n'))
            break;
    }
    free(buffer);
    if (!homie || *homie == '\0')
    {
        free(homie);
        homie = NULL;
        return (NULL);
    }
    line = extr_f_homie(&homie);
    if (!line)
        return (free(line), NULL);
    return (line);
}
char *extr_f_homie(char **homie)
{
    int i;
    char *line;
    char *tmp;

    1 && (i = 0, tmp = NULL);

    while ((*homie)[i] && (*homie)[i] != '\n')
        i++;
    if ((*homie)[i] == '\n')
    {
        line = malloc(i + 2);
        if (!line)
            return (NULL);
        strncpy(line, *homie, i + 1);
        line[i + 1] = '\0';
        tmp = strdup(*homie + i + 1);
        if (!tmp)
            return (NULL);
    }
    else
    {
        line = malloc(i + 1);
        if(!line)
            return (NULL);
        strncpy(line, *homie, i);
        line[i] = '\0';
        tmp = NULL;
    }
    return (free(*homie), *homie = tmp, line);
}
// char *get_next_line(int fd)
// {
//     static char *homie;
//     char *line;
//     char *buffer;
//     int c_bytes;

//     if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0)< 0)
//         return (free(homie), homie = NULL, NULL);
//     c_bytes = 1;
//     buffer = malloc(BUFFER_SIZE + 1);
//     if (!buffer)
//         return (free(homie), homie = NULL, NULL);
//     while (c_bytes > 0)
//     {
//         c_bytes = read(fd, buffer, BUFFER_SIZE);
//         if (c_bytes == 0)
//             break;
//         if (c_bytes < 0)
//             return (free(buffer), buffer = NULL, NULL);
//         buffer[c_bytes] = '\0';
//         homie = ft_strjoin(homie, buffer);
//         if (!homie)
//             return (free(buffer), buffer = NULL, NULL);
//         if (ft_strchr(homie, '\n'))
//             break;
//     }
//     free(buffer);
//     if (!homie || *homie == '\0')
//         return (free(homie), homie = NULL, NULL);
//     line = extr_f_homie(&homie);
//     if (!line)
//         return (free(line), NULL);
//     return (line);
// }
// char	*extr_f_homie(char **homie)
// {
//     int i;
//     char *line;
//     char *tmp;

//     i = 0;
//     tmp = NULL;
//    while ((*homie)[i] && (*homie)[i] != '\n')
//    {
//         i++;
//    }
//     if ((*homie)[i] == '\n')
//     {
//         line = malloc (i + 2);
//         if (!line)
//             return (NULL);
//         strncpy(line, *homie, i + 1);
//         line[i + 1] = '\0';
//         tmp = strdup(*homie + i + 1);
//         if (!tmp)
//             return (NULL);
//     }
//         else 
//         {
//             line = malloc (i + 1);
//             if (!line)
//                 return (NULL);
//             strncpy(line, *homie, i);
//             line[i] = '\0';
//             tmp = NULL;
//         }
//     return (free(*homie), *homie = tmp, line);
// }
// int main()
// {
// 	int fd;
// 	fd = open("file.txt", O_RDWR);
// 	char *tmp = get_next_line(fd);
// 	while (tmp)
// 	{
// 		printf("%s", tmp);
// 		free(tmp);
// 		tmp = get_next_line(fd);
// 	}
// 	close(fd);
// }