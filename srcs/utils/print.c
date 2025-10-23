/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbehar <sbehar@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:32:36 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/10/23 14:30:16 by sbehar           ###   ########.fr       */
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

void	ft_finish_reading(int fd)
{
	char	*line;

	line = "finish the reading plz";
	while (line)
	{
		line = get_next_line(fd);
		free(line);
	}
}
