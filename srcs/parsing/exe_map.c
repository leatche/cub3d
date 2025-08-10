/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 02:00:47 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/10 02:00:57 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_pars_the_line(t_parsing *pars, char *line)
{
	int	i;

	i = 0;
	pars->fd = 0;
	while (line[i] && ft_is_a_space(line[i]))
		i++;
	if (!line[i])
		return ("1");
	if (((line[i] == 'F' ) | (line[i] == 'C')) && ft_is_a_space(line[i + 1]))
		return ("1");
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
