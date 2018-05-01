/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:30:17 by einman            #+#    #+#             */
/*   Updated: 2018/04/19 11:30:18 by einman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		newstr[i] = f(i, s[i]);
	return (newstr);
}
