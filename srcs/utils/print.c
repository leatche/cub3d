/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:32:36 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/10/12 22:49:50 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_print(char *a)
{
	printf("Error\n" "%s\n", a);
}

t_point	point(int x, int y)
{
	t_point	dest;

	dest.x = x;
	dest.y = y;
	return (dest);
}
