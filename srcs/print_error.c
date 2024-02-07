/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:21:37 by rbarbier          #+#    #+#             */
/*   Updated: 2023/11/16 16:57:30 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/*==========COLORS==========/
Red : \033[0;31m
Green : \033[0;32m
Yellow : \033[0;33m
Blue : \033[0;34m
Purple : \033[0;35m
Cyan : \033[0;36m
White : \033[0;37m
DEFAULT : \033[0m

/==========ERRORS==========/
0 : No error
1 : Number of exits invalid
2 : Number of initial positions invalid
3 : Number of collectibles invalid
4 : Invalid character in map
5 : Edges of the map invalid
6 : Map is not squared
7 : Malloc error
*/

void	print_error(int error)
{
	ft_printf("\033[0;31mError\n\033[0m");
	if (error == 1)
		ft_printf("[number of exits \"\033[0;34mE\033[0m\" invalid].");
	else if (error == 2)
		ft_printf(\
		"[number of initial positions \"\033[0;34mP\033[0m\" invalid].");
	else if (error == 3)
		ft_printf("[number of collectibles \"\033[0;34mC\033[0m\" invalid].");
	else if (error == 4)
		ft_printf("[invalid character found].");
	else if (error == 5)
		ft_printf("[invalid edges].");
	else if (error == 6)
		ft_printf("[map is not squared].");
	else if (error == 7)
		ft_printf("[malloc error].");
	else if (error == 8)
		ft_printf("[map is not possible].");
	else if (error == 9)
		ft_printf("[number of arguments invalid].");
	else if (error == 10)
		ft_printf("[map file invalid].");
	exit (1);
}

int	finish(void)
{
	exit (0);
	return (0);
}
