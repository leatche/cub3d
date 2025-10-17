/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbehar <sbehar@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:49:52 by sbehar            #+#    #+#             */
/*   Updated: 2025/10/17 18:15:11 by sbehar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_mouse_hook(int button, int x, int y, void *param)
{
	t_value *value;

	value = (t_value *)param;
	(void)x;
	(void)y;
	if (button == 4)
		ft_minimap_zoom_in(&value->minimap);
	else if (button == 5)
		ft_minimap_zoom_out(&value->minimap);
	return (0);
}

void	ft_update_player_orientation(t_value *value, int xoffset)
{
	double	sensitivity;
	double	rotation;

	sensitivity = 0.01f;
	rotation = xoffset * sensitivity;
	value->player->orientation += rotation;
}

int	ft_mouse_move(int x, int y, t_value *value)
{
	int	offset;

	(void)y;
	if (!value->mouse_on)
	{
		mlx_mouse_show(value->mlx, value->window);
		return (0);
	}
	offset = x - value->window_center_x;
	if (offset != 0)
		ft_update_player_orientation(value, offset);
	mlx_mouse_move(value->mlx, value->window, value->window_center_x, value->window_center_y);
	return (0);
}

void	ft_init_mouse(t_value *value)
{
	value->window_center_x = value->width / 2;
	value->window_center_y = value->height / 2;
	value->mouse_on = 1;
	value->img = mlx_new_image(value->mlx, value->width, value->height);
	value->minimap.cx = 110;
	value->minimap.cy = 110;
	value->minimap.radius = 80;
	value->minimap.scale = 6;
	mlx_mouse_hook(value->window, ft_mouse_hook, value);
	ft_update_map_size(&value->minimap, value->parsing->map);
}
