/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 01:58:54 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/25 22:32:16 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_add_to_map(char *a, t_list **list_tmp, t_parsing *pars)
{
	t_list	*new_content;
	char	*copy;

	if (!list_tmp || a == 0)
		return ;
	if (pars->map != NULL)
		return (ft_print("two times a map ... are you serious !!!"));
	if (strcmp(a, "1") != 0)
	{
		copy = ft_strdup(a);
		new_content = ft_lstnew(copy);
		if (!new_content)
			return ;
		if (ft_strlen(new_content->content) > pars->size_line)
			pars->size_line = ft_strlen(new_content->content);
		if (!*list_tmp)
			*list_tmp = new_content;
		else
			ft_lstadd_back(list_tmp, new_content);
	}
}

int	ft_conform_map(char **tmp)
{
	int	i;

	i = 0;
	while (tmp && tmp[i])
	{
		if (ft_checker_wall(tmp) == -1 || ft_good_characters(tmp[i]) == -1)
			return (-1);
		i++;
	}
	if (i != ft_size_tab(tmp))
	{
		ft_print("there is an empty line in the map ");
		return (-1);
	}
	return (GOOD);
}

int	ft_map_start(t_parsing *pars)
{
	if (pars->start == -1)
	{
		ft_print("your map is a the start ... that is a problem ...");
		return (BAD);
	}
	return (GOOD);
}

int	ft_check_wall_top(char *line)
{
	int	i;

	i = 0;
	if (!line || !*line)
		return (-1);
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (-1);
		i++;
	}
	return (0);
}
