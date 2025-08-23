/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:07:03 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/23 22:04:34 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <math.h>

#define DIR "ENWS"

t_player *create_player(int x, int y, char dir)
{
	t_player *player;
	char *tmp;

	tmp = ft_strchr(DIR, dir);
	player = malloc(sizeof(t_player));
	player->pos.x = x + 0.5;
	player->pos.y = y + 0.5;
	player->orientation = (tmp - DIR) * 90;
	return (player);
}

int	ft_has_a_player(t_parsing *pars)
{
	int	y;
	int	x;

	y = 0;
	while(pars->map[y])
	{
		x = 0;
		while (pars->map[y][x])
		{
			if (ft_strchr(DIR, pars->map[y][x]) != NULL)
			{
				if (pars->player != NULL)
					return (BAD);
				pars->player = create_player(x, y, pars->map[y][x]);
				pars->map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	return (GOOD);
}
