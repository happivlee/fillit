/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 19:35:58 by vlee              #+#    #+#             */
/*   Updated: 2018/04/27 19:36:06 by vlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//this file is for helper functions from list.c and helper.c - list.c first!!

//get coordinates function of current sqaure & stores it into the coordinate structure
t_coord	**get_coord(char *square, t_coord **shape_coord)
{
	int hash_count;
	int i;

	//allocates memory for 4 pointers
	shape_coord = (t_coord **)ft_memalloc(sizeof(t_coord *) * 4);
	i = 0;
	while (i < 4)
	{
		//for each pointer, it allocates memory for 4 coordinates to be stored - for each #
		shape_coord[i] = (t_coord *)ft_memalloc(sizeof(t_coord));
		i++;
	}
	//s_row and s_col aren't needed with he address method of passing pointer?
	i = 0;
	hash_count = 0;
	while (hash_count < 4 && square[i])
	{
		//if we encounter a #
		if (square[i] == '#')
		{
			//set the row value and column value for that #
			shape_coord[hash_count]->row = (i / 5);
			shape_coord[hash_count]->col = (i % 5);
			//increment to prepare for when square[i] encounters another hash
			hash_count++;
		}
		i++;
	}
	//returns a complete coordinate for the entire tetramino whose coordinates you're trying to save;
	return (shape_coord);
}

//save_element function
void	save_tetra(char *square, t_tetralist **current_list)
{
	t_tetralist	*new;
	int			list_length;

	new = *current_list;
	//check if the is the first tetrmino. If it is create it.
	if (!new)
	{
		new = (t_tetralist *)ft_memalloc(sizeof(t_tetralist));
		new->shape_coord = get_coord(square, new->shape_coord);
		new->print = 'A';
		new->next = NULL;
		*current_list = new;
		return ;
	}
	//set new list element.
	list_length = 1;
	while (new->next && ++list_length)
		new = new->next;
	new->next = (t_tetralist *)ft_memalloc(sizeof(t_tetralist));
	new->next->shape_coord = get_coord(square, new->shape_coord);
	new->next->print = list_length + 'A';
	new->next->next = NULL;
}

//puts the tetramino in the sqaure if it fits.
int		place_tetra(t_square *sqr, t_tetralist *current_tetra, int y, int x)
{
	int hash;
	int row;
	int col;

	hash = -1;
	while (++hash < 4)
	{
		row = y + current_tetra->shape_coord[hash]->row;
		col = x + current_tetra->shape_coord[hash]->col;
		if (row >= sqr->size || col >= sqr->size || /
		sqr->solution_map[row][col] != '.')
			return (0);
		sqr->solution_map[row][col] = current_tetra->print;
	}
	return (1);
}

void	remove_tetra(t_square *sqr, t_tetralist *current_tetra)
{
	int i;
	int j;

	i = 0;
	while (i < sqr->size)
	{
		
	}
}