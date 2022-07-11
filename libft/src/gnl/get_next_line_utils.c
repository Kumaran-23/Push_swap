/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 14:41:50 by snair             #+#    #+#             */
/*   Updated: 2022/02/16 15:52:59 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*n_str;

	if (!str)
	{
		str = (char *)malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	if (!str || !buff)
		return (NULL);
	n_str = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(buff)) + 1));
	if (n_str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (str)
		while (str[++i])
			n_str[i] = str[i];
	while (buff[j])
		n_str[i++] = buff[j++];
	n_str[ft_strlen(str) + ft_strlen(buff)] = '\0';
	free(str);
	return (n_str);
}

int	ft_findline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i += 1;
			break ;
		}
		i++;
	}
	return (i);
}

char	*ft_getline(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = ft_findline(str);
	j = 0;
	line = 0;
	if (!str)
		return (NULL);
	if (i > 0)
	{
		line = (char *)malloc(sizeof(char) * (i + 1));
		while (j < i)
		{
			line[j] = str[j];
			j++;
		}
		line[j] = '\0';
	}
	return (line);
}
