/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetraminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 20:23:43 by vlee              #+#    #+#             */
/*   Updated: 2018/04/24 20:23:57 by vlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//may need to put in a 3rd parameter int s, so that we know where to save element to
int l_shape(char *square, t_tlist **inputlist)
{
	if (square[5] == '#' && square[10] == '#' && square[11] == '#')
	{
		//need to have s b/c that's how the element is saved... ::create save element fcn first::
		//s was only used for get_cordinate and not needed if we pass teh string.
		save_tetra(inputlist, square)
		return (1);
	}
	//^can modify from the 1st correct shape w/ the coordinates that you wrote down (Victoria)
}

int j_shape(char *square, t_tlist **inputlist)
{

}

int s_z_shape(char *square, t_tlist **inputlist)
{

}

int t_shape(char *square, t_tlist **inputlist)
{

}

int i_o_shape(char *square, t_tlist **inputlist)
{

}
