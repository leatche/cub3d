/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcherepoff <tcherepoff@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:00:30 by tcherepoff        #+#    #+#             */
/*   Updated: 2024/11/17 23:06:21 by tcherepoff       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	slen;

	if (!s || start > ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	slen = ft_strlen(s);
	if (len + start > slen)
		slen = slen - start;
	else if (len < slen)
		slen = len;
	str = malloc(sizeof(char) * (slen + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (len-- > 0 && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
