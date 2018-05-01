/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 12:01:15 by einman            #+#    #+#             */
/*   Updated: 2018/04/22 12:01:17 by einman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char			*itoa;
	size_t			len;
	unsigned int	c;

	len = ft_intlen(n);
	c = n;
	if (n < 0)
	{
		c = -n;
		len++;
	}
	if (!(itoa = ft_strnew(len)))
		return (NULL);
	itoa[--len] = c % 10 + '0';
	while (c /= 10)
		itoa[--len] = c % 10 + '0';
	if (n < 0)
		itoa[0] = '-';
	return (itoa);
}
