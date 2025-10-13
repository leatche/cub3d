/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbehar <sbehar@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 02:03:31 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/10/13 14:04:04 by sbehar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_parsing(t_value *value, t_parsing *pars)
{
	if (ft_has_a_player(value, pars) == BAD)
	{
		ft_print("there is too much or no player in the map !!");
		return (-1);
	}
	if (ft_conform_map(pars->map) == -1)
		return (-1);
	return (0);
}

int	ft_open(char *file, t_parsing *parsing)
{
	int	fd;
	int	a;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (BAD);
	ft_initialize_pars(parsing);
	a = ft_transfer_map(fd, parsing);
	if (ft_final_pars_map(parsing, a) == BAD)
		return (BAD);
	return (GOOD);
}

void	ft_initialize_pars(t_parsing *pars)
{
	pars->map = NULL;
	pars->start = 0;
	pars->size_line = 0;
	pars->hasCeiling = 0;
	pars->hasFloor = 0;
}

int	ft_here(t_parsing *pars)
{
	if (pars->hasFloor == 0)
	{
		ft_print("there is no floor color :)");
		return (BAD);
	}
	if (pars->hasCeiling == 0)
	{
		ft_print("there is no ceiling color :(");
		return (BAD);
	}
	return (GOOD);
}

int	ft_final_pars_map(t_parsing *pars, int a)
{
	if (a == -1)
		return (BAD);
	// présence de tout
	if (ft_here(pars) == BAD)
		return (BAD);
	return (GOOD);
}
