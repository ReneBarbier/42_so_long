/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_possible.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:17:37 by rbarbier          #+#    #+#             */
/*   Updated: 2023/11/16 11:40:04 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	get_initial_point(char **map, int *y, int *x)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	j = 0;
	while (map[j])
	{
		if (map[j][i] == 'C')
			count++;
		if (map[j][i] == 'P')
		{
			*x = i;
			*y = j;
		}
		i++;
		if (map[j][i] == '\0')
		{
			i = 0;
			j++;
		}
	}
	return (count + 1);
}

int	check_cell(char **map, int y, int x, t_points **lst)
{
	t_points	*tmp;

	if (map[y][x] == '0' || map[y][x] == 'C' || map[y][x] == 'E')
	{
		tmp = ft_lstnew(y, x);
		if (!tmp)
			return (-7);
		ft_lstadd_back(lst, tmp);
		if (map[y][x] == 'C')
			map[y][x] = 'c';
		else if (map[y][x] == 'E')
			map[y][x] = 'e';
		else
			map[y][x] = 'X';
	}
	return (0);
}

int	check_neightbors(char **map, t_points *cur_p, t_points **lst, int *c_amount)
{
	t_points	*tmp;
	int			ret_value;

	ret_value = 0;
	if (map[cur_p->y][cur_p->x] == 'c' \
	|| map[cur_p->y][cur_p->x] == 'e')
		(*c_amount)--;
	if (*c_amount == 0)
		return (0);
	ret_value += check_cell(map, cur_p->y - 1, cur_p->x, lst);
	ret_value += check_cell(map, cur_p->y + 1, cur_p->x, lst);
	ret_value += check_cell(map, cur_p->y, cur_p->x + 1, lst);
	ret_value += check_cell(map, cur_p->y, cur_p->x - 1, lst);
	tmp = (*lst)->next;
	free(*lst);
	*lst = tmp;
	if (ret_value == 0)
		return (1);
	else
		return (7);
}

int	map_possible(char **map)
{
	t_points	*search_list;
	t_points	*tmp;
	int			x;
	int			y;
	int			c_amount;

	x = 0;
	y = 0;
	c_amount = get_initial_point(map, &y, &x);
	search_list = ft_lstnew(y, x);
	while (search_list)
	{
		tmp = search_list;
		x = check_neightbors(map, tmp, &search_list, &c_amount);
		if (x != 1)
			return (free(search_list), x);
	}
	return (8);
}
