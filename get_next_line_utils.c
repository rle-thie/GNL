/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:19:19 by rle-thie          #+#    #+#             */
/*   Updated: 2022/01/03 15:48:57 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char    *ft_strchr(const char *s, int c)
{
        size_t  i;

        i = 0;
        while (s[i] && s[i] != (char)c)
                i++;
        if (s[i] == (char)c)
                return ((char *)&s[i]);
        else
                return (NULL);
}

char    *ft_strjoin(char const *s1, char const *s2)
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
        return (tab);
}