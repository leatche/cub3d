/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:24:11 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/10/16 21:21:01 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_checker_wall(char **tmp)
{
	int	result;

	result = ft_check_sides(tmp, ft_size_tab(tmp));
	if (result == -1)
	{
		ft_print("there is a hole in the side your map...");
		return (-1);
	}
	result = ft_check_wall(tmp);
	if (result == -1)
	{
		ft_print("there is a hole in your map...");
		return (-1);
	}
	return (1);
}

int	ft_check_sides(char **tmp, int size)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (tmp[i])
	{
		if (i == 0 || i == (size - 1))
			result = ft_check_wall_top(tmp[i]);
		else
			result = ft_check_side_wall(tmp[i]);
		if (result == -1)
			return (result);
		i++;
	}
	return (result);
}

int	ft_check_wall(char **tmp)
{
	int	i;
	int	j;

	i = 1;
	while (tmp[i])
	{
		j = 1;
		while (tmp[i][j])
		{
			if (tmp[i][j] == '0' && ft_check_zero(tmp, i, j) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_zero_safe(char **map, int i, int j)
{
	int	height;
	int	curr_len;
	int	len_up;
	int	len_down;

	height = ft_size_tab(map);
	if (i + 1 >= height || i - 1 < 0)
		return (-1);
	curr_len = ft_strlen(map[i]);
	len_up = ft_strlen(map[i - 1]);
	len_down = ft_strlen(map[i + 1]);
	if (j + 1 >= curr_len || j - 1 < 0)
		return (-1);
	if (j >= len_up || j >= len_down)
		return (-1);
	if ((j - 1 < 0) || (j + 1 >= curr_len))
		return (-1);
	if ((j - 1 >= len_up) || (j - 1 >= len_down))
		return (-1);
	if ((j + 1 >= len_up) || (j + 1 >= len_down))
		return (-1);
	return (1);
}

int	ft_check_zero_spaces(char **tmp, int i, int j)
{
	if (tmp[i + 1][j] == ' ')
		return (-1);
	if (tmp[i - 1][j] == ' ')
		return (-1);
	if (tmp[i][j + 1] == ' ')
		return (-1);
	if (tmp[i][j - 1] == ' ')
		return (-1);
	if (tmp[i - 1][j - 1] == ' ')
		return (-1);
	if (tmp[i + 1][j - 1] == ' ')
		return (-1);
	if (tmp[i + 1][j + 1] == ' ')
		return (-1);
	if (tmp[i - 1][j + 1] == ' ')
		return (-1);
	return (1);
}

int	ft_check_zero(char **map, int i, int j)
{
	if (ft_check_zero_safe(map, i, j) == -1)
		return (-1);
	if (ft_check_zero_spaces(map, i, j) == -1)
		return (-1);
	return (1);
}

int	ft_check_side_wall(char *line)
{
	int	i;

	i = 0;
	while (ft_is_a_space(line[i]))
		i++;
	if (line[i] != '1')
		return (-1);
	i = ft_strlen(line) - 1;
	while (ft_is_a_space(line[i]))
		i--;
	if (line[i] != '1')
		return (-1);
	return (0);
}
