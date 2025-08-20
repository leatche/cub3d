/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 23:39:53 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/20 17:19:55 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

#define Z 122
#define W 119

#define Q 113
#define A 97

#define S 115
#define D 100
#define UP 65362
#define LEFT 65361
#define DOWN 65364
#define RIGHT 65363
#define ESC 65307

int key_press(int keycode, t_value *value)
{
	(void)value;
	// value->parsing->start = 0;
	// if (keycode == 123)
	// 	;
	// if (keycode == 124)
	// 	;
	if (keycode == ESC)
		exit(0);
	return (0);
}
