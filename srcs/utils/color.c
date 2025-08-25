/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 22:35:28 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/25 22:39:44 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_color	color(int r, int g, int b)
{
	t_color	dest;

	dest.r = r;
	dest.g = g;
	dest.b = b;
	return (dest);
}

t_color	yellow(void)
{
	t_color	dest;

	dest.r = 255;
	dest.g = 255;
	dest.b = 0;
	return (dest);
}

t_color	green(void)
{
	t_color	dest;

	dest.r = 0;
	dest.g = 255;
	dest.b = 0;
	return (dest);
}
