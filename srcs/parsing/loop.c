/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:26:33 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/10/10 13:04:20 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_go_for_backward(t_value *value)
{
	if (value->keys.go_forward)
	{
		value->player->pos.x
			+= cos(value->player->orientation / 360 * (2 * PI)) / 30;
		value->player->pos.y
			+= -sin(value->player->orientation / 360 * (2 * PI)) / 30;
	}
	if (value->keys.go_backward)
	{
		value->player->pos.x
			-= cos(value->player->orientation / 360 * (2 * PI)) / 30;
		value->player->pos.y
			-= -sin(value->player->orientation / 360 * (2 * PI)) / 30;
	}
}

void	ft_go_left_right(t_value *value)
{
	if (value->keys.go_left)
	{
		value->player->pos.x
			+= cos((value->player->orientation + 90) / 360 * (2 * PI)) / 30;
		value->player->pos.y
			+= -sin((value->player->orientation + 90) / 360 * (2 * PI)) / 30;
	}
	if (value->keys.go_right)
	{
		value->player->pos.x
			+= cos((value->player->orientation - 90) / 360 * (2 * PI)) / 30;
		value->player->pos.y
			+= -sin((value->player->orientation - 90) / 360 * (2 * PI)) / 30;
	}
}

int	ft_loop(t_value *value)
{
	if (value->keys.turn_left)
		value->player->orientation += 6;
	if (value->keys.turn_right)
		value->player->orientation -= 6;
	ft_go_for_backward(value);
	ft_go_left_right(value);
	value->player->color = color(54, 87, 74);
	ft_draw_map(value);
	return (1);
}
