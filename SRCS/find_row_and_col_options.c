/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_row_and_col_options.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 18:35:51 by jchuah            #+#    #+#             */
/*   Updated: 2025/08/18 03:06:53 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

//counts the number of permutations that match the clue
static void	count_matches(t_towers *towers,
int *clue_matches, int clue_match_size)
{
	t_perm	*perms;
	int		clue_match_indx;
	int		i;

	perms = towers->perms;
	i = 0;
	while (i < towers->perm_count)
	{
		clue_match_indx
			= perms[i].left_vis * clue_match_size + perms[i].right_vis;
		clue_matches[clue_match_indx]++;
		i++;
	}
}

static int	fill_row_options(t_towers *towers,
int *clue_matches, int clue_match_size)
{
	t_permlst	*row_options;
	int			*left_clue;
	int			*right_clue;
	int			i;

	row_options = towers->row_options;
	left_clue = &towers->clues[towers->grid_size * 2];
	right_clue = &towers->clues[towers->grid_size * 3];
	i = 0;
	while (i < towers->grid_size)
	{
		row_options[i].size
			= clue_matches[*left_clue * clue_match_size + *right_clue];
		if (row_options[i].size == 0)
			return (0);
		row_options[i].perms
			= (t_perm *)malloc(row_options[i].size * sizeof(t_perm));
		if (!row_options[i].perms)
			return (ft_printf("Memory allocation error\n") * 0 + 21);
		fill_matches(towers, row_options[i].perms, *left_clue, *right_clue);
		left_clue++;
		right_clue++;
		i++;
	}
	return (0);
}

static int	fill_col_options(t_towers *towers,
int *clue_matches, int clue_match_size)
{
	t_permlst	*col_options;
	int			*up_clue;
	int			*down_clue;
	int			i;

	col_options = towers->col_options;
	up_clue = &towers->clues[0];
	down_clue = &towers->clues[towers->grid_size];
	i = 0;
	while (i < towers->grid_size)
	{
		col_options[i].size
			= clue_matches[*up_clue * clue_match_size + *down_clue];
		if (col_options[i].size == 0)
			return (0);
		col_options[i].perms
			= (t_perm *)malloc(col_options[i].size * sizeof(t_perm));
		if (!col_options[i].perms)
			return (ft_printf("Memory allocation error\n") * 0 + 21);
		fill_matches(towers, col_options[i].perms, *up_clue, *down_clue);
		up_clue++;
		down_clue++;
		i++;
	}
	return (0);
}

static int	fill_options(t_towers *towers,
int *clue_matches, int clue_match_size)
{
	int	errorcode;

	errorcode = fill_row_options(towers, clue_matches, clue_match_size);
	if (errorcode != 0)
		return (errorcode);
	errorcode = fill_col_options(towers, clue_matches, clue_match_size);
	if (errorcode != 0)
		return (errorcode);
	return (0);
}

int	find_row_and_col_options(t_towers *towers)
{
	int	errorcode;
	int	*clue_matches;
	int	clue_match_size;

	clue_match_size = towers->grid_size + 1;
	clue_matches
		= (int *)ft_calloc(clue_match_size * clue_match_size, sizeof(int));
	if (!clue_matches)
	{
		free(clue_matches);
		free_towers(towers);
		return (20);
	}
	count_matches(towers, clue_matches, clue_match_size);
	errorcode = fill_options(towers, clue_matches, clue_match_size);
	free(clue_matches);
	if (errorcode != 0)
	{
		free_towers(towers);
		return (errorcode);
	}
	return (0);
}
