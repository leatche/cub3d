/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:04:17 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/10/16 00:07:43 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_extension(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (i < 5)
	{
		ft_print("that's not a good file typo :)");
		return (BAD);
	}
	if (strcmp(file + i - 4, ".cub") == 0)
		return (GOOD);
	ft_print("there is no .cub at the end :)");
	return (BAD);
}

int	ft_is_a_space(char a)
{
	if (a == ' ' || a == '\t')
		return (1);
	return (0);
}

int	ft_good_characters(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_strchr("NSEW10 ", line[i]) == 0)
		{
			ft_print("Be careful, there is a wrong chacracter !");
			return (BAD);
		}
		i++;
	}
	return (GOOD);
}
