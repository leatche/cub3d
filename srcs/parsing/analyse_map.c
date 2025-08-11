/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 01:58:54 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/11 22:00:53 by tcherepoff       ###   ########.fr       */
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
		if (!*list_tmp)
			*list_tmp = new_content;
		else
			ft_lstadd_back(list_tmp, new_content);
	}
}

int	ft_read_lines(int fd, t_parsing *pars)
{
	t_list	*list_tmp;
	char	*line;
	char	*a;

	line = "";
	list_tmp = NULL;
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		a = ft_pars_the_line(pars, line);
		if (a == line)
			ft_add_to_map(line, &list_tmp, pars);
		free (line);
	}
	pars->map = ft_list_to_tab(list_tmp);
	ft_lstclear(&list_tmp, free);
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

int	ft_check_side_wall(char *line)
{
	int	i;

	i = 0;
	while (ft_is_a_space(line[i]))
		i++;
	if (line[i] != '1')
		return (-1);
	i = ft_strlen(line) - 1;
	while (ft_is_a_space(line[i]))
		i--;
	if (line[i] != '1')
		return (-1);
	return (0);
}

int	ft_good_characters(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N'
			&& line[i] != 'W' && line[i] != 'E' && line[i] != 'S'
			&& line[i] != ' ')
		{
			ft_print("Be careful, there is a wrong chacracter !");
			return (BAD);
		}
		i++;
	}
	return (GOOD);
}
