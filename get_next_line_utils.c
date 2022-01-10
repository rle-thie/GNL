/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:19:19 by rle-thie          #+#    #+#             */
/*   Updated: 2022/01/05 19:17:51 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}


int	ft_strchr(char *s, char c)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			if (s[i] == c)
				return (1);
			i++;
		}
	}
	return (0);
}

char    *ft_strjoin(char *s1, char *s2)
{
	size_t  lentt;
	char    *tab;
	size_t  i;
	size_t  y;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	y = 0;
	lentt = ft_strlen(s1) + ft_strlen(s2);
	tab = malloc(sizeof(char) * (lentt + 1));
	if (!tab)
		return (NULL);
	while (s1[y])
		tab[i++] = s1[y++];
	y = 0;
	while (s2[y])
		tab[i++] = s2[y++];
	tab[i] = '\0';
	free(s1);
	return (tab);
}
