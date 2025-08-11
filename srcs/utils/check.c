/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:04:17 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/11 18:28:33 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_extension(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (i < 5)
		return (BAD);
	if (strcmp(file + i - 4, ".cub") == 0)
		return (GOOD);
	return (BAD);
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

int	ft_is_a_space(char a)
{
	if (a == ' ' || a == '\t')
		return (1);
	return (0);
}

void	ft_initialize_pars(t_parsing *pars)
{
	pars->map = NULL;
	pars->floor.r = 0;
	pars->floor.b = 0;
	pars->floor.g = 0;
	pars->wall.r = 0;
	pars->wall.b = 0;
	pars->wall.g = 0;
}
