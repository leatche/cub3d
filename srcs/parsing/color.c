/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:20:09 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/20 13:21:11 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_pars_color(char *line, t_parsing *pars)
{
	t_color	*tmp;

	if (line[0] == 'F')
		tmp = &pars->floor;
	else
		tmp = &pars->wall;
	if (tmp->b != 0 && tmp->r != 0 && tmp->g != 0)
	{
		ft_print("you declare two times color ! Pay attention pleaseeee.");
		return ("-1");
	}
	if (ft_norm_color(line, tmp) == -1)
	{
		ft_print("Check again your definition of color... where are we ?");
		return ("-1");
	}
	return ("1");
}

int	ft_norm_color(char *line, t_color *tmp)
{
	int	i;
	int	count;
	unsigned char *colors;

	colors = (unsigned char *)tmp;
	i = 2;
	count = 0;
	while (line[i])
	{
		while (ft_is_a_space(line[i]))
			i++;
		if (ft_value_color(line + i, colors + 2 - count) == BAD)
			return (BAD);
		count++;
		while (ft_isdigit(line[i]))
			i++;
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (line[i] != ',' || count > 2)
			break ;
		i++;
	}
	if (count != 3 || line[i])
		return (BAD);
	return (GOOD);
}

int	ft_value_color(char *line, unsigned char *color)
{
	int	result;
	int i;

	if (!*line || !ft_isdigit(*line))
		return (BAD);
	result = ft_atoi(line);
	if (result < 0 || result > 255)
	{
		printf("Number must be between 0 and 255\n");
		return (BAD);
	}
	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	if (i > 3)
	{
		printf("Number has more than 3 digits\n");
		return (BAD);
	}
	*color = (unsigned char)result;
	return (GOOD);
}
