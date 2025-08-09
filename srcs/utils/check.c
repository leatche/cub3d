/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 18:04:17 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/09 23:52:54 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_extension(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (i < 5)
		return (BAD);
	if (strcmp(file + i - 4, ".cub") == 0)
		return (GOOD);
	return (BAD);
}

int	ft_open(char *file, t_parsing *pars)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (BAD);
	return (ft_read_lines(fd, pars));
}

int	ft_read_lines(int fd, t_parsing *pars)
{
	t_list	**list_tmp;
	char	*line;
	char	*a;

	line = "";
	list_tmp = NULL;
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (line && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		a = ft_pars_the_line(pars, line);
		if (a != -1)
			ft_lstadd_back(list_tmp, ft_lstnew(a));
		free (line);
		free (a); //? faut 'il d'abord le malloc ??? 
	}
	pars->map = ft_list_to_tab(list_tmp);
	// ft_free_list();
	return GOOD;
}

char	*ft_pars_the_line(t_parsing *pars, char *line)
{
	int	i;

	i = 0;
	pars->fd = 0;
	while (line[i] && ft_is_a_space(line[i]))
		i++;
	if (!line[i])
		return (55);
	if (((line[i] == 'F' ) | (line[i] == 'C')) && ft_is_a_space(line[i + 1]))
		return (1);
	if ((ft_strncmp(line + i, "NO", 2) == 0) && ft_is_a_space(line[i + 2]))
		return (2);
	if ((ft_strncmp(line + i, "SO", 2) == 0) && ft_is_a_space(line[i + 2]))
		return (3);
	if ((ft_strncmp(line + i, "WE", 2) == 0) && ft_is_a_space(line[i + 2]))
		return (4);
	if ((ft_strncmp(line + i, "EA", 2) == 0) && ft_is_a_space(line[i + 2]))
		return (5);
	return (line);
}

int	ft_is_a_space(char a)
{
	if (a == ' ' || a == '\t')
		return (1);
	return (0);
}

char	**ft_list_to_tab(t_list **list_tmp)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = malloc(sizeof (char *) * (ft_lstsize(*list_tmp) + 1));
	while ((*list_tmp)->next)
	{
		tmp[i] = (*list_tmp)->content;
		printf ("voic tmi %s\n", tmp[i]);
		(*list_tmp) = (*list_tmp)->next;
		i++;
	}
	tmp[i] = (*list_tmp)->content;
	(*list_tmp) = (*list_tmp)->next;
	return (tmp);
}
