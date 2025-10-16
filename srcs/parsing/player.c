/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:07:03 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/10/16 21:35:37 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

int	ft_has_a_player(t_value *value)
{
	int			y;
	int			x;
	t_player	*tmp_player;

	y = -1;
	while (value->parsing->map[++y])
	{
		x = -1;
		while (value->parsing->map[y][++x])
		{
			if (ft_strchr(DIR, value->parsing->map[y][x]) != NULL)
			{
				if (value->player != NULL)
					return (BAD);
				tmp_player = create_player(x, y, value->parsing->map[y][x]);
				if (tmp_player == NULL)
					return (BAD);
				value->player = tmp_player;
				value->parsing->map[y][x] = '0';
			}
		}
	}
	if (value->player == NULL)
		return (BAD);
	return (GOOD);
}
