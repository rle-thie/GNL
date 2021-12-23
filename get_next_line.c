/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:59:30 by rle-thie          #+#    #+#             */
/*   Updated: 2021/12/22 17:31:16 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*get_next_line(int fd, char *buf)
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

int	main(void)
{
	int			fd;
	static char	*buf;
	char		*tab;

	fd = open("test.txt", 'r');
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (1);
	tab = get_next_line(fd, buf);
	printf("%s\n", tab);
	return (0);
}