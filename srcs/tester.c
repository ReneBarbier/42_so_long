/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:28:26 by rbarbier          #+#    #+#             */
/*   Updated: 2023/11/16 17:00:56 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	draw_ball(t_vars *vr, int x, int y)
{
	static int	moves = 0;

	ft_printf("Moves: %d\n", moves++);
	draw_ball_extra(vr, x, y);
	mlx_put_image_to_window(vr->mlx, vr->win, \
		vr->player, x * 50 + 4, y * 50 + 8);
	if (vr->map[vr->y][vr->x] == 'C')
	{
		vr->c_amount--;
		if (vr->c_amount == 0)
			open_door(vr->map, 0, 0, vr);
		vr->map[vr->y][vr->x] = '0';
	}
}

void	walk(t_vars *vr, int dir)
{
	if (dir == 1)
		if (vr->map[vr->y - 1][vr->x] != '1')
			draw_ball(vr, vr->x, vr->y - 1);
	if (dir == 2)
		if (vr->map[vr->y + 1][vr->x] != '1')
			draw_ball(vr, vr->x, vr->y + 1);
	if (dir == 3)
		if (vr->map[vr->y][vr->x - 1] != '1')
			draw_ball(vr, vr->x - 1, vr->y);
	if (dir == 4)
		if (vr->map[vr->y][vr->x + 1] != '1')
			draw_ball(vr, vr->x + 1, vr->y);
}

int	move_player(int keycode, t_vars *vr)
{
	if (keycode == 0)
		walk(vr, 3);
	else if (keycode == 1)
		walk(vr, 2);
	else if (keycode == 2)
		walk(vr, 4);
	else if (keycode == 13)
		walk(vr, 1);
	else if (keycode == 53)
	{
		mlx_destroy_window(vr->mlx, vr->win);
		exit(0);
	}
	return (0);
}

void	paint_map(char **map, t_vars *vr, int x, int y)
{
	while (map[y])
	{
		if (map[y][x] == '0' || map[y][x] == 'P')
			mlx_put_image_to_window(vr->mlx, vr->win, \
				vr->floor, x * 50, y * 50);
		else if (map[y][x] == '1')
			mlx_put_image_to_window(vr->mlx, vr->win, vr->wall, x * 50, y * 50);
		else if (map[y][x] == 'E')
			mlx_put_image_to_window(vr->mlx, vr->win, \
				vr->close_door, x * 50, y * 50);
		else if (map[y][x] == 'C')
		{
			mlx_put_image_to_window(vr->mlx, vr->win, \
				vr->floor, x * 50, y * 50);
			mlx_put_image_to_window(vr->mlx, vr->win, \
				vr->coin, x * 50 + 15, y * 50 + 15);
		}
		if (!map[y][++x])
		{
			x = 0;
			y++;
		}
	}
}

void	tester(char **map)
{
	t_vars	vr;

	vr.cells_x = 0;
	vr.cells_y = 0;
	while (map[0][vr.cells_x])
		vr.cells_x++;
	while (map[vr.cells_y])
		vr.cells_y++;
	vr.height = vr.cells_y * 50;
	vr.width = vr.cells_x * 50;
	vr.radius = 10;
	vr.map = map;
	vr.c_amount = get_initial_point(map, &vr.y, &vr.x) - 1;
	vr.mlx = mlx_init();
	vr.win = mlx_new_window(vr.mlx, vr.width, vr.height, "Ball Animation");
	init_imgs(&vr);
	paint_map(map, &vr, 0, 0);
	draw_ball(&vr, vr.x, vr.y);
	mlx_key_hook(vr.win, move_player, &vr);
	mlx_hook(vr.win, 17, 0, finish, &vr);
	mlx_loop(vr.mlx);
}
