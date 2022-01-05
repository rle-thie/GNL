/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:18:39 by rle-thie          #+#    #+#             */
/*   Updated: 2022/01/05 16:38:18 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>

size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
char    *ft_strchr(const char *s, int c);
char    *ft_strjoin(char *s1, char *s2);

#endif