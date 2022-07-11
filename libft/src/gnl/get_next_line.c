/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snair <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 19:36:51 by snair             #+#    #+#             */
/*   Updated: 2022/02/16 11:07:08 by snair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_nextline(char *str)
{
	int		i;
	int		j;
	char	*line;

	i = ft_findline(str);
	j = 0;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	while (!line)
		return (NULL);
	while (str[i + j])
	{
		line[j] = str[i + j];
		j++;
	}
	line[j] = '\0';
	free(str);
	return (line);
}

char	*ft_read_str(int fd, char *str)
{
	int		readbytes;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	readbytes = 1;
	while (!ft_strchr(str, '\n') && readbytes != 0)
	{
		readbytes = read(fd, buff, BUFFER_SIZE);
		if (readbytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[readbytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read_str(fd, str);
	if (!str)
		return (NULL);
	line = ft_getline(str);
	str = ft_nextline(str);
	return (line);
}
