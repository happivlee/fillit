/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:11:49 by einman            #+#    #+#             */
/*   Updated: 2018/04/18 15:11:50 by einman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t i;

	i = -1;
	while (++i < n)
	{
		if (src[i])
			dst[i] = src[i];
		else
			while (i < n)
				dst[i++] = '\0';
	}
	return (dst);
}
