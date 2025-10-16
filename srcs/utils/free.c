/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 23:10:35 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/10/16 21:07:54 by tcherepoff       ###   ########.fr       */
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
	free(pars->textures[NORTH]);
	free(pars->textures[SOUTH]);
	free(pars->textures[EAST]);
	free(pars->textures[WEST]);
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
	if (value->render3d.texture_north.img_ptr)
		mlx_destroy_image(value->mlx, value->render3d.texture_north.img_ptr);
	if (value->render3d.texture_south.img_ptr)
		mlx_destroy_image(value->mlx, value->render3d.texture_south.img_ptr);
	if (value->render3d.texture_east.img_ptr)
		mlx_destroy_image(value->mlx, value->render3d.texture_east.img_ptr);
	if (value->render3d.texture_west.img_ptr)
		mlx_destroy_image(value->mlx, value->render3d.texture_west.img_ptr);
	mlx_destroy_window(value->mlx, value->window);
	mlx_destroy_display(value->mlx);
	free(value->mlx);
	free(value->player);
	free(value);
}
