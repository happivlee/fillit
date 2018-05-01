/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:45:31 by einman            #+#    #+#             */
/*   Updated: 2018/04/19 11:45:33 by einman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	newstr = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!newstr)
		return (NULL);
	while (s1[++i])
		newstr[i] = s1[i];
	while (s2[++j])
		newstr[i++] = s2[j];
	return (newstr);
}
