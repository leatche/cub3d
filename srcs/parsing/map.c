/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 02:00:47 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/11 19:08:00 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_pars_the_line(t_parsing *pars, char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_is_a_space(line[i]))
		i++;
	if (!line[i])
		return ("1");
	if (((line[i] == 'F' ) | (line[i] == 'C')) && ft_is_a_space(line[i + 1]))
		return (ft_pars_color(line, pars, line[i]));
	if ((ft_strncmp(line + i, "NO", 2) == 0) && ft_is_a_space(line[i + 2]))
		return ("1");
	if ((ft_strncmp(line + i, "SO", 2) == 0) && ft_is_a_space(line[i + 2]))
		return ("1");
	if ((ft_strncmp(line + i, "WE", 2) == 0) && ft_is_a_space(line[i + 2]))
		return ("1");
	if ((ft_strncmp(line + i, "EA", 2) == 0) && ft_is_a_space(line[i + 2]))
		return ("1");
	return (line);
}

int	ft_pars_color(char *line, t_parsing *pars, char place)
{
	t_color	tmp;

	if (place == 'F')
		tmp = pars->floor;
	else
		tmp =pars->wall;
	if (tmp.b != 0 && tmp.r != 0 && tmp.g != 0)
	{
		ft_print("you declare two times color ! Pay attention pleaseeee.");
		return (-1);
	}
	if (ft_norm_color(tmp, line) == -1)
	{
		ft_print("Check again your definition of color... where are we ?");
		return (-1);
	}
	return (0);
}

int	ft_norm_color(t_color color, char *line)
{
	int	i;
	int	count;

	i = 2;
	count = 0;
	while (line[i])
	{
		while (ft_is_a_space(line[i]))
			i++;
		i = ft_value_color(line, i, color, count);
		if (i == -1)
			return (-1);
		count++;
		while (ft_is_a_space(line[i]))
			i++;
		if (line[i] != ',' && count < 2)
			return (-1);
		else
			i++;
	}
	if (count != 2)
		return (-1);
}

int	ft_value_color(char *line, int i, t_color color, int coco)
{
	int	count;

	count = 0;
	if (!line[i] || !ft_isdigit(line[i]))
		return (-1);
	while (line[i] && ft_isdigit(line[i]))
		count++;
	if (coco == 0)
		ft_memcpy(color.r, line + i - count, count);
	if (coco == 1)
		ft_memcpy(color.g, line + i - count, count);
	if (coco == 2)
		ft_memcpy(color.b, line + i - count, count);
	if (color.r > 255)
		return (-1);
	return (i);
}
