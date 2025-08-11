/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 02:03:31 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/10 19:31:04 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_parsing(t_parsing *pars)
{
	// if (ft_has_a_player == BAD)
	// {
	// 	ft_print("there is too much or no player in the map !!");
	// 	return (-1);
	// }
	if (ft_conform_map(pars->map) == BAD)
		return (-1);
	return (0);
}

int	ft_conform_map(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (ft_checker_wall(tmp[i], i, ft_size_tab(tmp)) == BAD
			|| ft_good_characters(tmp[i]) == BAD)
			return (BAD);
		i++;
	}
	if (i != ft_size_tab(tmp))
	{
		ft_print("there is an empty line in the map ");
		return (BAD);
	}
	return (GOOD);
}

int	ft_checker_wall(char *line, int i, int size)
{
	int	result;

	if (i == 0 || i == (size - 1))
		result = ft_check_wall_top(line);
	else
		result = ft_check_side_wall(line);
	if (result == -1)
	{
		ft_print("there is a hole in your map...");
		return (BAD);
	}
	return (GOOD);
}
