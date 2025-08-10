/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 02:03:31 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/10 03:27:44 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_parsing(t_parsing *pars)
{
	int	i;
	char **tmp;
	// int	size_tab;

	i = 0;
	tmp = pars->map;
	// size_tab = ft_size_tab(*(pars->map));
	while (tmp[i])
	{
		if (ft_checker_wall(tmp[i], i, ft_strlen(*tmp)) == BAD
			|| ft_good_characters(tmp[i]))
				return (-1);
		i++;
	}
	if (i != ft_strlen(*tmp))
	{
		ft_print("there is an empty line in the map ");
		return (-1);
	}
	// if (ft_has_a_player == BAD)
	// {
	// 	ft_print("there is too much or no player in the map !!");
	// 	return (-1);
	// }
}

// int	ft_size_tab(char **map)
// {
// // ft_size_tab(*(pars->map))
// }

int	ft_checker_wall(char *line, int i, int size)
{
	int	result;

	if (i == 0 || i == size)
		result = ft_check_wall_top(line);
	else
		result = ft_check_side_wall(line);
	if (result == -1)
	{
		ft_print("there is a hole in your map...");
		return (BAD);
	}

}

int	ft_check_wall_top(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (i != '1' && i != ' ')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_check_side_wall(char *line)
{
	int	i;

	i = 0;
	while (ft_is_a_space(line[i]))
		i++;
	if (line[i] != '1')
		return (-1);
	i = ft_strlen(line);
	while (ft_is_a_space(line[i]))
		i--;
	if (line[i] != '1')
		return (-1);
	return (0);
}
