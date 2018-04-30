/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:57:55 by vlee              #+#    #+#             */
/*   Updated: 2018/04/24 16:15:59 by vlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	verify_square(char *square)
{
	int hash_count;
	int i;

	hash_count = 0;
	i = 0;
	while(square[i])
	{
		if (square[i] != '.' || square[i] != '#' || square[i] != '\n')
			return (0);
		if (square[i] == '#')
			hash_count++;
		if (square[i] == '\n')
		{
			if (!(i = 4 || i = 9 || i = 14 || i = 19 || i = 20))
				return (0);
		}
		i++;
	}
	return (hash_count == 4 ? 1 : 0);
}

//Juo's method of detecting tetraminos - it includes verifying the square
int get_shape(char *square, t_tlist **list)
{
	int i;

	i = -1;
	if((verify_shape(square)) == 0)
		return (0);
	while (square[++i] != '#')
	//check to see if it's various types of tetraminos
		//return (1) if it is
	if (l_shape(&square[i], list))
		return (1);
	else if (j_shape(&square[i], list))
		return (1);
	else if (s_z_shape(&square[i], list))
		return (1);
	else if (t_shape(&square[i], list))
		return (1);
	else if (i_o_shape(&square[i], list))
		return (1);
	return (0);
}

//checks for a valid shape - not sure how this saves coordinates based on the related github..
int	check_tetra(char *square, t_tetralist **current_list)
{
	int peripheral_match;
	int i;

	i = 0;
	peripheral_match = 0;

	while (i < 20)
	{
		if (square[i] == '#')
		{
			if ((i + 1) < 20 && square[i + 1] == '#')
				peripheral_match++;
			if ((i - 1) >= 0 && square[i - 1] == '#')
				peripheral_match++;
			if ((i + 5) < 20 && square[i + 5] == '#')
				peripheral_match++;
			if ((i - 5) >= 0 && square[i - 5] == '#')
				peripheral_match++;
		}
		i++;
	}
	i = 0;
	while (square[i++] != '#')	//this should work - verify later when testing!
	if (peripheral_match == 6 || peripheral_match == 8)
		save_tetra(&square[i], list);
	return (peripheral_match == 6 || peripheral_match == 8);
}

//reads the input text that may contain valid tetraminos
int	read_file(int fd, t_tetralist **current_list)
{
	//take fd from main and verify + fill in the tetraminos.
	char *buffer;
	char nl;

	buffer = ft_strnew(22);
	nl = 'z';
	while (read(fd, buffer, 21) > 0)
	{
		//check to see if the block read is a valid square && tetramino
		if (!verify_shape(*square) || !check_tetra(square, current_list))
			return (0);
		//check to see if last char read is a new line if it's not zero
		if (buffer[20] != '\n' && read(fd, buffer, 21) > 0)
			return (0);
		nl = buffer[20];
		ft_bzero(buffer, 22);
	}
	if (nl != '\0')
		return (0);
	return (1);
}
