/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:59:30 by rle-thie          #+#    #+#             */
/*   Updated: 2021/12/22 15:42:51 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	k = 0;

char	*get_next_line(int fd)
{
	FILE	*fp;
	
	fp = fopen("/test.txt", "r");
	fclose(fp);
}

int main(void)
{
	printf("%s\n", get_next_line("test.txt"));
	return (0);
}