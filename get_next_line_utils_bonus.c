/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyahansa <zyahansa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:44:37 by zyahansa          #+#    #+#             */
/*   Updated: 2024/12/10 13:44:40 by zyahansa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	ft_strcpy(result, s1);
	ft_strcpy(result + len1, s2);
	return (free(s1), result);
}

char	*ft_strchr(const char *s, int c)
{
	char	target;
	int		i;

	target = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == target)
			return ((char *)&s[i]);
		i++;
	}
	if (target == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char		*tab;
	size_t		i;
	size_t		len;

	len = ft_strlen(s1);
	tab = (char *)malloc(len + 1);
	if (!tab)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
