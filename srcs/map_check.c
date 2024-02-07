/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:17:29 by rbarbier          #+#    #+#             */
/*   Updated: 2023/11/13 16:30:19 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	character_check(char *input)
{
	int	i;
	int	e_flag;
	int	c_flag;
	int	p_flag;

	i = -1;
	e_flag = 0;
	c_flag = 0;
	p_flag = 0;
	while (input[++i])
	{
		if (chr_check_extra(input[i], &e_flag, &c_flag, &p_flag))
			return (4);
	}
	if (e_flag != 1)
		return (1);
	if (p_flag != 1)
		return (2);
	if (c_flag != 1)
		return (3);
	return (0);
}

void	fill_map(char ***map, char *input, int total_lines)
{
	int	i;
	int	j;
	int	line;

	i = 0;
	j = 0;
	line = 0;
	while (line > total_lines)
	{
		if (input[i] == '\n')
		{
			*map[line++][j] = '\0';
			j = 0;
		}
		else
			*map[line][j++] = input[i];
		i++;
	}
	*map[line] = 0;
}

int	is_squared(char **map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (map[k][j])
		j++;
	while (map[k])
	{
		while (map[k][i])
			i++;
		if (i != j)
			return (6);
		i = 0;
		k++;
	}
	return (0);
}

int	edges_check(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		if (!map[j][i])
		{
			j++;
			i = 0;
			continue ;
		}
		if (j == 0 || !map[j + 1] || i == 0 || map[j][i + 1] == 0)
		{
			if (map[j][i] != '1')
				return (5);
		}
		i++;
	}
	return (0);
}

int	map_check(char *input, char ***map)
{
	int		ret_value;
	int		end_line;

	end_line = 0;
	while (input[end_line] != '\n')
		end_line++;
	ret_value = character_check(input);
	if (ret_value != 0)
		return (ret_value);
	*map = ft_split(input, '\n');
	if (!*map)
		return (7);
	ret_value = is_squared(*map);
	if (ret_value != 0)
		return (ret_value);
	ret_value = edges_check(*map);
	if (ret_value != 0)
		return (ret_value);
	return (0);
}
