/* ************************************************************************** */
/*	*/
/*	:::	  ::::::::   */
/*   transform.c	:+:	  :+:	:+:   */
/*	+:+ +:+	 +:+	 */
/*   By: tcherepoff <tcherepoff@student.42.fr>	  +#+  +:+	   +#+	*/
/*	+#+#+#+#+#+   +#+	   */
/*   Created: 2025/08/10 02:01:24 by tcherepoff	#+#	#+#	 */
/*   Updated: 2025/08/16 13:29:15 by tcherepoff	   ###   ########.fr	   */
/*	*/
/* ************************************************************************** */

#include "cub.h"

int	is_empty_line(char *line)
{
	while (*line && ft_strchr("\f\t\n\r\v ", *line) != 0)
		line++;
	return (*line == 0);
}

int	ft_map_has_empty_line(t_list *map)
{
	int	has_empty_line;
	int	is_empty;

	has_empty_line = 0;
	if (!map)
		return (GOOD);
	while (map)
	{
		((char *)map->content)[strlen(map->content) - 1] = '\0';
		is_empty = is_empty_line(map->content);
		if (!is_empty && has_empty_line == 1)
			return (BAD);
		if (is_empty)
			has_empty_line = 1;
		map = map->next;
	}
	return (GOOD);
}

char	**ft_list_to_tab(t_list *list_tmp, t_parsing *pars)
{
	int		i;
	t_list	*move;
	char	**tmp;

	i = 0;
	if (!list_tmp)
		return (NULL);
	tmp = malloc(sizeof (char *) * (ft_lstsize(list_tmp) + 1));
	move = list_tmp;
	while (move)
	{
		if (!is_empty_line(move->content))
		{
			tmp[i] = ft_strdup_space(move->content, pars->size_line);
			i++;
		}
		move = move->next;
	}
	tmp[i] = NULL;
	return (tmp);
}

char	*ft_strdup_space(char *s, int size_line)
{
	char	*result;
	char	*tmp;

	if (!s)
		return (NULL);
	tmp = ft_strtrim(s, "\n\r");
	result = malloc(size_line + 1);
	ft_memcpy(result, tmp, ft_strlen(tmp));
	ft_memset(result + ft_strlen(tmp), ' ', size_line - ft_strlen(tmp));
	result[size_line] = '\0';
	free(tmp);
	return (result);
}
