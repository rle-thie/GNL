/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:59:30 by rle-thie          #+#    #+#             */
/*   Updated: 2021/12/24 16:59:04 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// char	*ft_strtrim_front(char *str, char *stat)
// {
// 	int	i;
// 	int	len_stat;
// 	int	ttlen;
	
// 	len_stat = strlen(stat);
// 	ttlen = strlen(str) - len_stat;
// 	i = 0;
	
// 	while(str[i] && i < len)
// 	{
		
// 		i++;
// 	}
// }

char	*get_next_line(int fd)
{
	int		ok;
	char	*dest;
	int		i;
	static char	*buf;

	i = 0;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
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
	int		fd;
	char	*tab;
	char	*tab2;

	fd = open("test.txt", 'r');
	tab = get_next_line(fd);
	printf("%s\n", tab);
	tab2 = get_next_line(fd);
	printf("%s\n", tab2);
	free(tab2);
	return (0);
}