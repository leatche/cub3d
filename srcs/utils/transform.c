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
		tmp[i] = ft_strdup_space(move->content, pars->size_line);
		move = move->next;
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

char	*ft_strdup_space(char *s, int size_line)
{
	char	*result;

	if (!s)
		return (NULL);
	result = malloc(size_line + 1);
	ft_memcpy(result, s, ft_strlen(s));
	ft_memset(result + ft_strlen(s), ' ', size_line - ft_strlen(s));
	result[size_line] = '\0';
	return (result);
} 
