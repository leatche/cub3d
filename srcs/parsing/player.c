/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbehar <sbehar@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:07:03 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/10/13 09:29:34 by sbehar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <math.h>

t_player	*create_player(int x, int y, char dir)
{
	t_player	*player;
	char		*tmp;

	tmp = ft_strchr(DIR, dir);
	if (tmp == NULL)
	{
		ft_print("Invalid player direction character");
		return (NULL);
	}
	player = malloc(sizeof(t_player));
	if (player == NULL)
		return (NULL);
	player->pos.x = x + 0.5;
	player->pos.y = y + 0.5;
	player->orientation = (tmp - DIR) * 90;
	return (player);
}

int	ft_has_a_player(t_value *value, t_parsing *pars)
{
	int	y;
	int	x;
	t_player	*tmp_player;

	y = 0;
	while (pars->map[y])
	{
		x = 0;
		while (pars->map[y][x])
		{
			if (ft_strchr(DIR, pars->map[y][x]) != NULL)
			{
				if (value->player != NULL)
					return (BAD);
				tmp_player = create_player(x, y, pars->map[y][x]);
				if (tmp_player == NULL)
					return (BAD);
				value->player = tmp_player;
				pars->map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	if (value->player == NULL)
		return (ft_no_player());
	return (GOOD);
}

int	ft_no_player()
{
	ft_print("there is no player in the map, where are you ???");
	return (BAD);
}
