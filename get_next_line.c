/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:59:30 by rle-thie          #+#    #+#             */
/*   Updated: 2022/01/03 13:14:47 by rle-thie         ###   ########.fr       */
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
	int	i;
	char *tab;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (i == ft_strlen(str))
		return (NULL);
	if (str[i] == '\n')
		return (&str[i+1]);
}

char	*full_file(int fd, char *str)
{
	int	count;
	int	i;
	char *tab;

	i = 0;
	count = read(fd, str, BUFFER_SIZE);
	str[count] = '\0';
	tab = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!tab)
		return (NULL);
	while (i < ft_strlen(str))
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	free(str);
	// printf("%s\n", tab);
	return (tab);
}

char	*read_line(char *str)
{
	int i;
	char *tab;
	
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	tab = malloc(sizeof(char) * i + 1);
	if (!tab)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		tab[i] = str[i];
		i++;
	}
	// free(str);
	return (tab);
}

char *get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!buf)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		buf = full_file(fd, buf);
	}
	
	line = read_line(buf);
	// printf("'%s'\n", buf);
	buf = ft_strtrim_front(buf);
	// printf("'%s'\n", buf);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*tab;
	char	*tab2;
	// char	*tab3;

	fd = open("test.txt", 'r');
	tab = get_next_line(fd);
	printf("ligne : %s.\n", tab);
	tab2 = get_next_line(fd);
	printf("ligne : %s.", tab2);
	// tab2 = get_next_line(fd);
	// printf("--%s--", tab2);
	// free(tab);
	return (0);
}