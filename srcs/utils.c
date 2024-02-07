/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:34:25 by rbarbier          #+#    #+#             */
/*   Updated: 2023/11/16 11:39:32 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	chr_check_extra(char chr, int *e_f, int *c_f, int *p_f)
{
	if (chr == 'E')
		(*e_f)++;
	else if (chr == 'P')
		(*p_f)++;
	else if (chr == 'C')
		(*c_f) = 1;
	else if (chr != '0' && chr != '1' && chr != '\n')
		return (1);
	return (0);
}

void	init_imgs(t_vars *vr)
{
	vr->floor = mlx_xpm_file_to_image(vr->mlx, \
		"img/floor.xpm", &vr->img_w, &vr->img_w);
	vr->wall = mlx_xpm_file_to_image(vr->mlx, \
		"img/wall.xpm", &vr->img_w, &vr->img_w);
	vr->close_door = mlx_xpm_file_to_image(vr->mlx, \
		"img/close_door.xpm", &vr->img_w, &vr->img_w);
	vr->open_door = mlx_xpm_file_to_image(vr->mlx, \
		"img/open_door.xpm", &vr->img_w, &vr->img_w);
	vr->player = mlx_xpm_file_to_image(vr->mlx, \
		"img/invader.xpm", &vr->img_w, &vr->img_w);
	vr->coin = mlx_xpm_file_to_image(vr->mlx, \
		"img/coin.xpm", &vr->img_w, &vr->img_w);
}

void	draw_ball_extra(t_vars *vr, int x, int y)
{
	static int	in_exit = 0;

	if (in_exit == 0)
		mlx_put_image_to_window(vr->mlx, vr->win, \
			vr->floor, vr->x * 50, vr->y * 50);
	else
		mlx_put_image_to_window(vr->mlx, vr->win, \
			vr->close_door, vr->x * 50, vr->y * 50);
	vr->x = x;
	vr->y = y;
	if (vr->map[vr->y][vr->x] == 'E')
	{
		if (vr->c_amount == 0)
		{
			ft_printf("\033[0;32mCompleted!\n");
			exit(0);
		}
		else
			in_exit = 1;
	}
	else
		in_exit = 0;
}

char	**map_reseat(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == 'X')
				map[j][i] = '0';
			else if (map[j][i] == 'e' || map[j][i] == 'c')
				map[j][i] -= 32;
			i++;
		}
		i = 0;
		j++;
	}
	return (map);
}

void	open_door(char **map, int x, int y, t_vars *vr)
{
	while (map[y])
	{
		if (map[y][x] == 'E')
			mlx_put_image_to_window(vr->mlx, \
				vr->win, vr->open_door, x * 50, y * 50);
		if (!map[y][++x])
		{
			x = 0;
			y++;
		}
	}
}
