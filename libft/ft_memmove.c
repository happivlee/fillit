/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:53:32 by einman            #+#    #+#             */
/*   Updated: 2018/04/18 13:53:33 by einman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*csrc;
	char		*cdst;
	size_t		i;

	i = -1;
	csrc = (char *)src;
	cdst = (char *)dst;
	if (csrc < cdst)
	{
		while ((int)(--n) >= 0)
			*(cdst + n) = *(csrc + n);
	}
	else
		while (++i < n)
			*(cdst + i) = *(csrc + i);
	return (dst);
}
