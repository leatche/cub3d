/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbehar <sbehar@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:21:13 by sbehar            #+#    #+#             */
/*   Updated: 2025/10/17 18:21:34 by sbehar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_check_zero_safe(char **map, int i, int j)
{
	int	height;
	int	curr_len;
	int	len_up;
	int	len_down;

	height = ft_size_tab(map);
	if (i + 1 >= height || i - 1 < 0)
		return (-1);
	curr_len = ft_strlen(map[i]);
	len_up = ft_strlen(map[i - 1]);
	len_down = ft_strlen(map[i + 1]);
	if (j + 1 >= curr_len || j - 1 < 0)
		return (-1);
	if (j >= len_up || j >= len_down)
		return (-1);
	if ((j - 1 < 0) || (j + 1 >= curr_len))
		return (-1);
	if ((j - 1 >= len_up) || (j - 1 >= len_down))
		return (-1);
	if ((j + 1 >= len_up) || (j + 1 >= len_down))
		return (-1);
	return (1);
}

int	ft_check_zero_spaces(char **tmp, int i, int j)
{
	if (tmp[i + 1][j] == ' ')
		return (-1);
	if (tmp[i - 1][j] == ' ')
		return (-1);
	if (tmp[i][j + 1] == ' ')
		return (-1);
	if (tmp[i][j - 1] == ' ')
		return (-1);
	if (tmp[i - 1][j - 1] == ' ')
		return (-1);
	if (tmp[i + 1][j - 1] == ' ')
		return (-1);
	if (tmp[i + 1][j + 1] == ' ')
		return (-1);
	if (tmp[i - 1][j + 1] == ' ')
		return (-1);
	return (1);
}

int	ft_check_zero(char **map, int i, int j)
{
	if (ft_check_zero_safe(map, i, j) == -1)
		return (-1);
	if (ft_check_zero_spaces(map, i, j) == -1)
		return (-1);
	return (1);
}
