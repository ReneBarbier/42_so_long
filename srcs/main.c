/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:20:15 by rbarbier          #+#    #+#             */
/*   Updated: 2023/11/16 13:26:36 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	char	*line_map;
	char	**map;
	int		ret_value;

	if (argc != 2)
		print_error(9);
	line_map = read_map(argv[1], 0, 0);
	ret_value = map_check(line_map, &map);
	if (ret_value)
		print_error(ret_value);
	else
	{
		ret_value = map_possible(map);
		if (ret_value)
			print_error(ret_value);
		else
		{
			ft_printf("\033[0;32mMap is valid!\033[0m\n");
			map = map_reseat(map);
			tester(map);
		}
	}
	return (0);
}
