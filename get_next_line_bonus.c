/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:59:30 by rle-thie          #+#    #+#             */
/*   Updated: 2022/01/11 16:40:03 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*free_ptr(char *tab)
{
	free(tab);
	return (NULL);
}

char	*ft_strtrim_front(char *str)
{
	char		*stat;
	size_t		i;
	size_t		y;

	i = 0;
	y = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (free_ptr(str));
	stat = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!stat)
		return (NULL);
	stat[(ft_strlen(str) - i) - 1] = '\0';
	if (str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		stat[y] = str[i];
		i++;
		y++;
	}
	free(str);
	return (stat);
}

char	*read_buff(int fd, char *stat)
{
	int		count;
	char	*buf;

	count = 1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	while (ft_strchr(buf, '\n') == 0 && count > 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count < 0)
			break ;
		buf[count] = '\0';
		stat = ft_strjoin(stat, buf);
	}
	free(buf);
	return (stat);
}

char	*read_line(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		line = malloc(sizeof(char) * i + 1);
	else
		line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (free_ptr(line));
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!buf[fd])
	{
		buf[fd] = malloc(sizeof(char) * 1);
		if (!buf[fd])
			return (NULL);
		buf[fd][0] = '\0';
	}
	buf[fd] = read_buff(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = read_line(buf[fd]);
	buf[fd] = ft_strtrim_front(buf[fd]);
	return (line);
}

//  int	main(void)
//  {
// 	int		fd;
//  	char	*str;
// 	fd = open("test.txt", O_RDONLY);
// 	while ((str = get_next_line(fd)) != NULL)
// 	{
// 		printf ("%s", str);
// 		free(str);
// 	}
// 	return (0);
// }
