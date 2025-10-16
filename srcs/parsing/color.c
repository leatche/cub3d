/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:20:09 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/10/16 21:37:49 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_pars_color(char *line, t_parsing *pars)
{
	if (line[0] == 'F')
	{
		if (pars->has_floor || ft_norm_color(line, &pars->floor) == -1)
		{
			ft_print("Check again your floor definition");
			return (free(line), LINE_ERROR);
		}
		pars->has_floor = 1;
	}
	else
	{
		if (pars->has_ceiling || ft_norm_color(line, &pars->ceiling) == -1)
		{
			ft_print("Check again your ceiling definition");
			return (free(line), LINE_ERROR);
		}
		pars->has_ceiling = 1;
	}
	free(line);
	return (LINE_INFO);
}

int	ft_norm_color(char *line, t_color *tmp)
{
	int				i;
	int				count;
	unsigned char	*colors;

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
	int	i;

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
