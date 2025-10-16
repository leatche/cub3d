/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 02:00:47 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/10/16 00:03:17 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_pars_texture(t_parsing *pars, char *line)
{
	(void)pars;
	free(line);
	return (LINE_INFO);
}

int ft_pars_the_line(t_parsing *pars, char *line)
{
	char *trimed;

	trimed = ft_strtrim(line, "\f\t\n\r\v ");
	if (!trimed[0])
	{
		free(trimed);
		return (LINE_EMPTY);
	}
	if (((trimed[0] == 'F' ) || (trimed[0] == 'C')) && ft_is_a_space(trimed[1]))
		return (ft_pars_color(trimed, pars));
	if ((ft_strncmp(trimed, "NO", 2) == 0) && ft_is_a_space(trimed[2]))
		return (ft_pars_texture(pars, trimed));
	if ((ft_strncmp(trimed, "SO", 2) == 0) && ft_is_a_space(trimed[2]))
		return (ft_pars_texture(pars, trimed));
	if ((ft_strncmp(trimed, "WE", 2) == 0) && ft_is_a_space(trimed[2]))
		return (ft_pars_texture(pars, trimed));
	if ((ft_strncmp(trimed, "EA", 2) == 0) && ft_is_a_space(trimed[2]))
		return (ft_pars_texture(pars, trimed));
	free(trimed);
	return (LINE_MAP);
}

int	ft_transfer_map(int fd, t_parsing *pars)
{
	t_list	*list_tmp;

	list_tmp = ft_read_lines(fd, pars);
	if (!list_tmp || list_tmp == NULL)
		return (-1);
	pars->map = ft_list_to_tab(list_tmp, pars);
	ft_lstclear(&list_tmp, free);
	return (0);
}

t_list	*ft_read_lines(int fd, t_parsing *pars)
{
	t_list	*list_tmp;
	char	*line;

	line = "";
	list_tmp = NULL;
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_check_trap(pars, line, &list_tmp) == BAD)
			return (ft_lstclear(&list_tmp, free), free(line), NULL);
		free(line);
	}
	if (list_tmp == NULL)
		ft_print("Your map is missing ;o");
	return (list_tmp);
}

int	ft_check_trap(t_parsing *pars, char *line, t_list **list_tmp)
{
	int line_type;

	if (!line[0] && *list_tmp == NULL)
		return (GOOD);
	line_type = ft_pars_the_line(pars, line);
	if (line_type == LINE_ERROR)
		return (BAD);
	if (line_type == LINE_EMPTY && pars->hasMap)
	{
		ft_print("There are a some empty lines in your map ;)");
		return (BAD);
	}
	if (line_type != LINE_MAP)
		return (GOOD);
	if (pars->hasMap == 0)
	{
		pars->hasMap = 1;
		if (pars->hasFloor == 0 || pars->hasCeiling == 0)
		{
			ft_print("Your map is missing or wrongly placed ;o");
			return (BAD);
		}
	}
	ft_add_to_map(line, list_tmp, pars);
	return (GOOD);
}
