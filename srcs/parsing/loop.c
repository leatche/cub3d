/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbehar <sbehar@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:26:33 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/10/17 18:08:30 by sbehar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_loop(t_value *value)
{
	ft_handle_rotation(value);
	ft_handle_up_and_down(value);
	ft_handle_right_and_left(value);
	value->player->color = color(54, 87, 74);
	ft_draw_walls(value);
	ft_draw_minimap_circle(value, &value->minimap, 0x222222);
	ft_draw_minimap_map(value, &value->minimap);
	mlx_put_image_to_window(value->mlx, value->window, value->img, 0, 0);
	ft_draw_minimap_compass(value, &value->minimap);
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