/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:45:21 by jchuah            #+#    #+#             */
/*   Updated: 2025/08/18 04:22:03 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include "libft.h"

# define GRID_SIZE_MAX	9
# define SOLVED			1
# define UNSOLVED		0
# define UP				0
# define DOWN			1
# define LEFT			2
# define RIGHT			3

//stores a permutation and the clues it matches
typedef struct s_permutation
{
	int	values[GRID_SIZE_MAX];
	int	left_vis;
	int	right_vis;
}	t_perm;

//list of perms that will fit a particular clue
//indx is of the chosen perm
typedef struct s_permlst
{
	t_perm	*perms;
	int		size;
	int		indx;
}	t_permlst;

//perms stores every possible perm for a row of towers
//row_options are the possible perms for each row
typedef struct s_towers
{
	int			grid_size;
	int			perm_count;
	t_perm		*perms;
	t_permlst	row_options[GRID_SIZE_MAX];
	t_permlst	col_options[GRID_SIZE_MAX];
	int			*clues;
	int			colmask[GRID_SIZE_MAX];
	int			rowmask[GRID_SIZE_MAX];
}	t_towers;

int		initialise_towers(char **argv, t_towers *towers);
void	generate_perms(t_towers *towers);
void	free_towers(t_towers *towers);
int		parse_clues(t_towers *towers, char **argv);
int		find_row_and_col_options(t_towers *towers);
void	fill_matches(t_towers *towers, t_perm *options, int clue1, int clue2);

//solving functions
int		solve_towers(t_towers *towers);
int		rowfits(t_towers *towers, int *candidate, int depth);
int		colfits(t_towers *towers, int *candidate, int depth);
void	addto_mask(int *mask, int *candidate, int size);
void	rmfrom_mask(int *mask, int *candidate, int size);
int		isplaced(int *mask, int *candidate, int size);
int		istopclue_conflict(t_towers *towers, int depth);
int		isbotclue_conflict(t_towers *towers, int depth);
int		isleftclue_conflict(t_towers *towers, int depth);
int		isrightclue_conflict(t_towers *towers, int depth);

void	print_towers(t_towers *towers);
#endif
