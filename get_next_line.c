/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:59:30 by rle-thie          #+#    #+#             */
/*   Updated: 2022/01/05 20:18:34 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*ft_strtrim_front(char *str)
{
	size_t		i;
	size_t		y;
	char	*stat;
	
	i = 0;
	y = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return(NULL);
	stat = malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!stat)
		return (NULL);
	stat[(ft_strlen(str) - i) - 1] = '\0';
	if (str[i] == '\n')
		i++;
	while(str[i] != '\0')
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
	size_t	count;
	char	*buf;

	count = 1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while((!ft_strchr(buf, '\n')) && count > 0)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count < 0)
			break ;
		buf[count] = '\0';
		stat = ft_strjoin(stat, buf);
		// printf("%s,%ld,%s\n", buf, count, stat);
	}
	free(buf);
	return (stat);
}

char	*read_line(char *str)
{
	size_t i;
	char *line;
	
	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while(str[i] != '\0' && str[i] != '\n')
		i++;
	// if (str[i] == '\0')
	// 	return (str);
	if (str[i] == '\0')
		line = malloc(sizeof(char) * i + 1);
	else
		line = malloc(sizeof(char) * i + 2);	
	if (!line)
		return (NULL);
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

char *get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf)
	{
		buf = malloc(sizeof(char) * 1);
		if (!buf)
			return (NULL);
		buf[0] = '\0';
	}
	buf = read_buff(fd, buf);
	// printf("static : %s\n", buf);
	if (!buf)
		return (NULL);
	line = read_line(buf);
	// printf("line = %s", line);
	buf = ft_strtrim_front(buf);
	// line = NULL;
	// printf("after trim : %s\n", buf);
	return (line);
}

 int	main(void)
 {
	int		fd;
 	char	*str;
	// char	*tab;
	// char	*tab2;
	// char	*tab3;

	fd = open("test.txt", O_RDONLY);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf ("%s", str);
		free(str);
	}
	// tab2 = get_next_line(fd);
	// printf("%s", tab2);
	// free(tab2);
	// tab = get_next_line(fd);
	// printf("%s", tab);
	// free(tab);
	return (0);
}