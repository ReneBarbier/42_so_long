/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:01:14 by rbarbier          #+#    #+#             */
/*   Updated: 2023/11/16 16:57:43 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../ft_printf/mandatory/inc/ft_printf.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*floor;
	void	*wall;
	void	*coin;
	void	*player;
	void	*close_door;
	void	*open_door;
	char	**map;
	int		c_amount;
	int		x;
	int		y;
	int		cells_x;
	int		cells_y;
	int		width;
	int		height;
	int		radius;
	int		img_w;
	int		img_h;
}	t_vars;

int		map_check(char *input, char ***map);
void	print_error(int error);
int		main(int argc, char **argv);
int		get_initial_point(char **map, int *y, int *x);
char	*read_map(char *path, int fd, int bytes_read);
int		map_possible(char **map);
int		chr_check_extra(char chr, int *e_f, int *c_f, int *p_f);
char	**map_reseat(char **map);
void	print_map(char **map);
void	tester(char **map);
void	draw_ball_extra(t_vars *vr, int x, int y);
void	init_imgs(t_vars *vr);
void	open_door(char **map, int x, int y, t_vars *vr);
int		finish(void);

#endif
