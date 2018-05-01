/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 12:16:46 by einman            #+#    #+#             */
/*   Updated: 2018/04/19 12:16:48 by einman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;
	int		k;

	if (!s || !(ret = (char **)malloc(sizeof(*ret) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_wordcount(s, c))
	{
		k = 0;
		if (!(ret[i] = ft_strnew(ft_wordlen(&s[j], c) + 1)))
			ret[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			ret[i][k++] = s[j++];
		ret[i][k] = '\0';
	}
	ret[i] = 0;
	return (ret);
}
