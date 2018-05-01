/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: einman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 15:37:57 by einman            #+#    #+#             */
/*   Updated: 2018/04/29 15:37:57 by einman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//creates && increments size of solution board
t_square    *new_square(int size)
{
	t_square    *square;
	int         i;
	int         j;

	//makes memory for the square
    square = (t_square *)ft_memalloc(sizeof(t_square));
    square->size = size;
	//make memory for the array of pointers to each tetramino stored
    square->solution_map = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	i = 0;
    j = 0;
    while (i < size)
    {
		//make memory for each row (length == size)
        square->solution_map[i] = (char *)ft_memalloc(sizeof(char) * (size + 1));
        j = 0;
        while (j < size)
        {
			//fill each spot in the row with a .
            square->solution_map[i][j] = '.';
            j++;
        }
        i++;
    }
	//returns a square made of .'s
    return (square);
}

//erases the solution square by freeing the memory
void	empty_square(t_square *solution_square, int size)
{
	//take the solution square and empty it from the inside out
	while (size + 1)
	{
		//free each row - may need to cast it (char **) for free to work
		free(solution_square->solution_map[size]);
		size--;
	}
	//free the array of pointers
	free(solution_square->solution_map);
	//free memory for the square
	free(solution_square);
}

//actually solves the square - 2 parameters: 1 = the current size square, 2 = the list of tetraminos that need to fit in the square
int	fill_square(t_square *solution_square, t_tetralist *complete_list)
{
	int i;
	int j;
	//do we need this? the list would never be empty, since it would have errored out during read file?
	if (complete_list == NULL)
		return (1);
	i = 0;
	while (i < solution_square->size)
	{
		j = 0;
		while (j < solution_square->size)
		{
			//if it successfully places the current tetra..
			if (place_tetra(solution_square, complete_list, i, j))
			{
				//check to see if there are other tetras??...do we have a solver fcn somewhere??
				if (fill_square(solution_square, complete_list->next))
					return (1);
				remove_tetra(solution_square, complete_list);
			}
			//move the tetra to the right one, and try again..
			j++;
		}
		//move the tetra down one row, and try again..
		i++;
	}
	return (0);
}
//this function initiates the solving process
t_square    *solve(t_tetralist *complete_list)
{
	    t_square *solution_square;
    int     size;

    size = 2;
    solution_square = new_square(size);
	//while filling the square with tetraminos doesn't provide a viable solution
    while (!fill_square(solution_square, complete_list)) //if list is empty, skips this, and returns an empty square
    {
		//empty the square, and
        empty_square(solution_square, size);
		//increase the size of the solution map by one
        size++;
		//set the square to the increased size
        solution_square = new_square(size);
    }
	//return the solved square! :)
    return (solution_square);
}
