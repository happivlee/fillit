/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:29:03 by einman            #+#    #+#             */
/*   Updated: 2018/04/25 13:29:05 by einman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char *argv[])
{
	int fd;
	int i;
	t_tetralist *tetras;
	t_square *final_square;

	tetras = NULL;
	if ((fd = open(argv[1], O_RDONLY)) == -1 || !read_file(fd, &tetras)))
	{
		ft_putstr("error\n");
		return (0);
	}
	if (argc !=2)
	{
		ft_putstr("usage: ./fillit input_file.txt\n");
		return (0);
	}
	final_square = solve(tetras);
	//output(final_square);
	return (0);
}
