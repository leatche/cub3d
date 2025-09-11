/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 23:39:53 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/28 15:58:52 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_press(int keycode, t_value *value)
{
	if (keycode == LEFT)
		value->keys.turn_left = 1;
	if (keycode == RIGHT)
		value->keys.turn_right = 1;
	if (keycode == Z)
		value->keys.go_forward = 1;
	if (keycode == S)
		value->keys.go_backward = 1;
	if (keycode == Q)
		value->keys.go_left = 1;
	if (keycode == D)
		value->keys.go_right = 1;
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
	if (keycode == Z)
		value->keys.go_forward = 0;
	if (keycode == S)
		value->keys.go_backward = 0;
	if (keycode == Q)
		value->keys.go_left = 0;
	if (keycode == D)
		value->keys.go_right = 0;
	return (0);
}
