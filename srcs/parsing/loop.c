/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbehar <sbehar@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:26:33 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/10/13 14:21:00 by sbehar           ###   ########.fr       */
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
	ft_draw_walls(value);
	draw_minimap_circle(value, &value->minimap, 0x222222);
	draw_minimap_map(value, &value->minimap);
	mlx_put_image_to_window(value->mlx, value->window, value->img, 0, 0);
	draw_minimap_compass(value, &value->minimap);
	return (1);
}

// int	ft_loop(t_value *value)
// {
// 	ft_handle_rotation(value);
// 	ft_handle_up_and_down(value);
// 	ft_handle_right_and_left(value);
// 	//value->player->color = random_color();
// 	ft_draw_walls(value);
// 	draw_minimap_circle(value, &value->minimap, 0x222222);
// 	draw_minimap_map(value, &value->minimap);
// 	mlx_put_image_to_window(value->mlx, value->window, value->img, 0, 0);
// 	draw_minimap_compass(value, &value->minimap);
// 	return (1);
// }