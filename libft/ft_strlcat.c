/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:44:45 by einman            #+#    #+#             */
/*   Updated: 2018/04/18 15:44:46 by einman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		j;
	size_t	dstlen;

	i = ft_strlen(dst);
	j = 0;
	dstlen = i;
	if (size < dstlen + 1)
		return (ft_strlen(src) + size);
	if (size > dstlen + 1)
	{
		while (i < size - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (dstlen + ft_strlen(src));
}
