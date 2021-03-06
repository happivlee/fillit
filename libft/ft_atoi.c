/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:51:35 by einman            #+#    #+#             */
/*   Updated: 2018/04/16 15:51:36 by einman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int ato;
	int i;
	int n;

	ato = 0;
	i = 0;
	n = 1;
	while ((str[i] < 14 && str[i] > 8) || str[i] == ' ')
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-')
	{
		n = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		ato = ato * 10 + str[i] - 48;
		i++;
	}
	return (ato * n);
}
