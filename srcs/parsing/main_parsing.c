/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 02:03:31 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/14 17:23:36 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_parsing(t_parsing *pars)
{
	// if (ft_has_a_player == -1)
	// {
	// 	ft_print("there is too much or no player in the map !!");
	// 	return (-1);
	// }
	if (ft_conform_map(pars->map) == -1)
		return (-1);
	return (0);
}

int	ft_conform_map(char **tmp)
{
	int	i;

	i = 0;
	while (tmp && tmp[i])
	{
		if (ft_checker_wall(tmp) == -1 || ft_good_characters(tmp[i]) == -1)
			return (-1);
		i++;
	}
	if (i != ft_size_tab(tmp))
	{
		ft_print("there is an empty line in the map ");
		return (-1);
	}
	return (GOOD);
}

int	ft_checker_wall(char **tmp)
{
	int	result;

	result = ft_check_sides(tmp, ft_size_tab(tmp));
	if (result == -1)
	{
		ft_print("line %s\nthere is a hole in your map...\n");
		return (-1);
	}
	result = ft_check_wall(tmp);
	if (result == -1)
	{
		ft_print("line %s\nthere is a hole in your map...\n");
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
