/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 23:10:35 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/10/10 12:23:04 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_free_parsing(t_parsing *pars)
{
	if (!pars)
		return (-1);
	if (pars->map)
		ft_free_tab(pars->map);
	free(pars->player);
	free(pars);
	return (-1);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_free_error(t_value *value)
{
	ft_free_parsing(value->parsing);
	free(value->player);
	free(value);
	return (-1);
}

void	ft_free_value(t_value *value)
{
	mlx_do_key_autorepeaton(value->mlx);
	mlx_destroy_image(value->mlx, value->img);
	mlx_destroy_window(value->mlx, value->window);
	mlx_destroy_display(value->mlx);
	free(value->mlx);
	free(value->player);
	free(value);
}
