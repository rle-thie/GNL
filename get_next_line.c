/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:59:30 by rle-thie          #+#    #+#             */
/*   Updated: 2021/12/24 18:07:10 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*ft_strtrim_front(char *stat, char *str)
{
	int	i;
	int	y;
	int	ttlen;
	char	*tab;

	y = 0;
	ttlen = ft_strlen(stat) - ft_strlen(str);
	if (ttlen <= 0)
		return (NULL);
	i = ft_strlen(str);
	tab = malloc(sizeof(char) * ttlen);
	tab[ttlen - 1] = '\0';
	if (!tab)
		return (NULL);
	//printf("l=%d.", stat[i]);
	if (stat[i] == '\n')
		i++;
	while(stat[i] && i < ft_strlen(stat))
	{
		tab[y] = stat[i];
		i++;
		y++;
	}
	return (tab);
}

char	*read_line(int fd, char *buf)
{
	int		ok;
	char	*dest;
	int		i;

	i = 0;
	ok = read(fd, buf, BUFFER_SIZE);
	buf[ok] = '\0';
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	dest = malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	dest[i] = '\0';
	i = -1;
	while (buf[++i] != '\0' && buf[i] != '\n')
		dest[i] = buf[i];
	free(buf);
	return (dest);
}

char *get_next_line(int fd)
{
	static char	*buf;
	char		*tab;
	
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	tab = read_line(fd, buf);
	return (tab);
}

int	main(void)
{
	int		fd;
	char	*tab = "abcdefghi";
	char	*tab2 = "abc";
	char	*tab3;

	fd = open("test.txt", 'r');
	// tab = get_next_line(fd);
	// printf("%s\n", tab);
	// tab2 = get_next_line(fd);
	// printf("%s\n", tab2);
	// free(tab2)
	printf("%s", ft_strtrim_front(tab, tab2));
	return (0);
}