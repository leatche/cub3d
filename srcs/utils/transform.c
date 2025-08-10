/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 02:01:24 by tcherepoff        #+#    #+#             */
/*   Updated: 2025/08/10 02:02:02 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	**ft_list_to_tab(t_list *list_tmp)
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
		tmp[i] = move->content;
		move = move->next;
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}
