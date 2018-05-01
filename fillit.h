/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 19:29:29 by vlee              #+#    #+#             */
/*   Updated: 2018/04/23 19:50:33 by vlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 21

#include <fcntl.h>
#include "libft/libft.h"

//struct will hold all valid tetraminos read
typedef struct	s_tetralist
{
	char 	print;
	//holds the coordinates of a given tetramino
	struct	s_coord	**shape_coord; //this holds the coordinates of the 4 points (linked)
	struct	s_tetralist	*next;
} 				t_tetralist;

//gives the coordinates of a single #
typedef struct	s_coord
{
	int	row;
	int col;
}				t_coord;

//struct used to create the solution map
typedef struct	s_square
{
	int size;
	char **solution_map;
}				t_square;

int			verify_square(char *square);
int			check_tetra(char *square, t_tetralist **current_list);
int			read_file(int fd, t_tetralist **data);
t_coord		**get_coord(char *square, t_coord **shape_coord);
void		save_tetra(char *square, t_tetralist **complete_list);
t_square    *new_square(int size);
void		empty_square(t_square *solution_square, int size);
int			fill_square(t_square *solution_square, t_tetralist *complete_list);
t_square    *solve(t_tetralist *clist);
int			place_tetra(t_square *sqr, t_tetralist *current_tetra, int y, int x);
void		remove_tetra(t_square *sqr, t_tetralist *current_tetra);
void		print_square(t_square *solution_square);

#endif
