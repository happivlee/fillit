/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:40:22 by einman            #+#    #+#             */
/*   Updated: 2018/04/19 11:40:23 by einman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*newstr;

	if (!s)
		return (NULL);
	newstr = ft_strnew(len + 1);
	if (!newstr)
		return (NULL);
	newstr = ft_strncpy(newstr, &s[start], len);
	newstr[len + 1] = '\0';
	return (newstr);
}
