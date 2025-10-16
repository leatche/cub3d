/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 23:39:53 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/10/16 21:29:06 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_press(int keycode, t_value *value)
{
	if (keycode == LEFT)
		value->keys.turn_left = 1;
	if (keycode == RIGHT)
		value->keys.turn_right = 1;
	if (keycode == Z || keycode == W)
		value->keys.go_forward = 1;
	if (keycode == S)
		value->keys.go_backward = 1;
	if (keycode == Q || keycode == A)
		value->keys.go_left = 1;
	if (keycode == D)
		value->keys.go_right = 1;
	if (keycode == M)
		value->mouse_on = !value->mouse_on;
	if (keycode == ESC)
		mlx_loop_end(value->mlx);
	return (1);
}

int	key_release(int keycode, t_value *value)
{
	if (keycode == LEFT)
		value->keys.turn_left = 0;
	if (keycode == RIGHT)
		value->keys.turn_right = 0;
	if (keycode == Z || keycode == W)
		value->keys.go_forward = 0;
	if (keycode == S)
		value->keys.go_backward = 0;
	if (keycode == Q || keycode == A)
		value->keys.go_left = 0;
	if (keycode == D)
		value->keys.go_right = 0;
	return (0);
}

void	ft_handle_rotation(t_value *value)
{
	if (value->keys.turn_right)
		value->player->orientation += 5;
	if (value->keys.turn_left)
		value->player->orientation -= 5;
}

void	ft_handle_up_and_down(t_value *value)
{
	double	angle_rad;
	double	speed;
	double	dx;
	double	dy;

	angle_rad = value->player->orientation / 360 * (2 * PI);
	speed = 1.0 / 30.0;
	if (value->keys.go_forward)
	{
		dx = cos(angle_rad) * speed;
		dy = -sin(angle_rad) * speed;
		ft_move_player(value, dx, dy);
	}
	if (value->keys.go_backward)
	{
		dx = -cos(angle_rad) * speed;
		dy = sin(angle_rad) * speed;
		ft_move_player(value, dx, dy);
	}
}

void	ft_handle_right_and_left(t_value *value)
{
	double	angle_rad;
	double	speed;
	double	dx;
	double	dy;

	angle_rad = value->player->orientation / 360 * (2 * PI);
	speed = 1.0 / 30.0;
	if (value->keys.go_right)
	{
		dx = cos(angle_rad + PI / 2) * speed;
		dy = -sin(angle_rad + PI / 2) * speed;
		ft_move_player(value, dx, dy);
	}
	if (value->keys.go_left)
	{
		dx = cos(angle_rad - PI / 2) * speed;
		dy = -sin(angle_rad - PI / 2) * speed;
		ft_move_player(value, dx, dy);
	}
}
