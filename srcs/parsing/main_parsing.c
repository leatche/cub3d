/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 02:03:31 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/09/28 19:16:02 by marvin           ###   ########.fr       */
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
	pars->floor_color.r = 0;
	pars->floor_color.b = 0;
	pars->floor_color.g = 0;
	pars->ceiling_color.r = 0;
	pars->ceiling_color.b = 0;
	pars->ceiling_color.g = 0;
}
