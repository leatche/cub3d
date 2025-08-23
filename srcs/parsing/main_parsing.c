/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 02:03:31 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/23 22:02:36 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_parsing(t_parsing *pars)
{
	if (ft_has_a_player(pars) == BAD)
	{
		ft_print("there is too much or no player in the map !!");
		return (-1);
	}
	if (ft_conform_map(pars->map) == -1)
		return (-1);
	return (0);
}

int	ft_open(char *file, t_parsing *pars)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (BAD);
	ft_initialize_pars(pars);
	return (ft_read_lines(fd, pars));
}

void	ft_initialize_pars(t_parsing *pars)
{
	pars->map = NULL;
	pars->start = 0;
	pars->size_line = 0;
	pars->floor.r = 0;
	pars->floor.b = 0;
	pars->floor.g = 0;
	pars->wall.r = 0;
	pars->wall.b = 0;
	pars->wall.g = 0;
}
