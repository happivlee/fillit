/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:20:45 by einman            #+#    #+#             */
/*   Updated: 2018/04/19 11:20:49 by einman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*newstr;
	int		i;

	if (!s)
		return (NULL);
	newstr = ft_strnew(ft_strlen(s));
	i = -1;
	if (!newstr)
		return (NULL);
	while (s[++i])
		newstr[i] = f(s[i]);
	return (newstr);
}
