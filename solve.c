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
void empty_square(t_square *solution_square, int size)
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

//actually solves the square
int fill_square(t_square *solution_square, t_tetralist *complete_list)
{
	int i;
	int j;
	if (complete_list == NULL)
		return (1);
	i = 0;
	while (i < solution_square->size)
	{
		j = 0;
		while (j < solution_square->size)
		{
			if (place_tetra(solution_square, complete_list, i, j))
			{
				if (solver(solution_square, complete_list->next))
					return (1);
				remove_tetra(solution_square, complete_list);
			}
			j++;
		}
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
    while (!fill_square(solution_square, complete_list))
    {
		//increase the size of the solution map by one
        size++;
		//empty the square, and
        empty_square(solution_square, size);
		//set the square to the increased size
        solution_square = new_square(size);
    }
	//return the solved square! :)
    return (solution_square);
}
