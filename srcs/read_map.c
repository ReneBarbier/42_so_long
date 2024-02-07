/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 12:56:50 by rbarbier          #+#    #+#             */
/*   Updated: 2023/11/14 12:38:40 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*read_map(char *path, int fd, int bytes_read)
{
	char	buff[2048];
	char	*map;

	fd = open(path, O_RDONLY);
	map = calloc(sizeof(char), 1);
	if (fd == -1)
		print_error(10);
	if (!map)
		print_error(7);
	while (1)
	{
		bytes_read = read(fd, buff, 2048);
		if (bytes_read == -1)
			print_error(11);
		if (bytes_read)
		{
			map = ft_strjoin(map, buff);
			if (!map)
				print_error(7);
		}
		else
			break ;
	}
	close(fd);
	return (map);
}
