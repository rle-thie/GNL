/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:59:30 by rle-thie          #+#    #+#             */
/*   Updated: 2022/01/05 16:01:44 by rle-thie         ###   ########.fr       */
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
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (i == ft_strlen(str))
		return (NULL);
	else if (str[i] == '\n')
		return (&str[i+1]);
	else
		return (NULL);
}

char	*full_file(int fd, char *str)
{
	size_t	count;
	char	*buf;
	
	count = 1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while(ft_strchr(buf, '\n') == 0 && count > 0)
	{
		count = read(fd, str, BUFFER_SIZE);
		if (count < 0)
		{
			break ;
		}
		str = ft_strjoin(buf, str);
	}
	free(buf);
	return (str);
}

char	*read_line(char *str)
{
	size_t i;
	char *tab;
	
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
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
	if (str[i] == '\n')
		tab[i] = str[i];
	// free(str);
	return (tab);
}

char *get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buf)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		buf[0] = '\0';
		buf = full_file(fd, buf);
	}
	line = read_line(buf);
	if (!buf)
		return (NULL);
	buf = ft_strtrim_front(buf);
	return (line);
}

 int	main(void)
 {
	int		fd;
 	char	*str;
	char	*tab;
	char	*tab2;
	char	*tab3;

	fd = open("test.txt", O_RDONLY);
	// while ((str = get_next_line(fd)) != NULL)
	// {
	// 	printf ("%s\n", str);
	// 	printf ("ROBIN LA SALOPE");
	// 	free(str);
	// }
	tab2 = get_next_line(fd);
	printf("%s", tab2);
	free(tab2);
	tab = get_next_line(fd);
	printf("%s", tab);
	free(tab);
	return (0);
}