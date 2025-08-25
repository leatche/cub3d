/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:24:11 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/25 22:33:09 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_checker_wall(char **tmp)
{
	int	result;

	result = ft_check_sides(tmp, ft_size_tab(tmp));
	if (result == -1)
	{
		ft_print("there is a hole in your map...");
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
	while (tmp[i])
	{
		if (i == 0 || i == (size - 1))
			result = ft_check_wall_top(tmp[i]);
		else
			result = ft_check_side_wall(tmp[i]);
		i++;
		if (result == -1)
			return (result);
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

int	ft_check_zero(char **tmp, int i, int j)
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
