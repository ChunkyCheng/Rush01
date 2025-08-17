/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_towers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:31:35 by jchuah            #+#    #+#             */
/*   Updated: 2025/08/18 04:29:18 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	col_search(t_towers *towers, int depth);

/*
static void	print_candidate(int *candidate, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
		ft_printf("%d ", candidate[i++]);
	ft_printf("%d\n", candidate[i]);
}
*/

static int	iscolclue_conflict(t_towers *towers, int depth)
{
	if (istopclue_conflict(towers, depth))
		return (1);
	if (isbotclue_conflict(towers, depth))
		return (1);
	return (0);
}

static int	isrowclue_conflict(t_towers *towers, int depth)
{
	if (isleftclue_conflict(towers, depth))
		return (1);
	if (isrightclue_conflict(towers, depth))
		return (1);
	return (0);
}

static int	row_search(t_towers *towers, int depth)
{
	int			option_indx;
	t_permlst	*row_options;
	int			*candidate;

	if (depth == towers->grid_size)
		return (SOLVED);
	option_indx = 0;
	row_options = &towers->row_options[depth];
	while (option_indx < row_options->size)
	{
		candidate = row_options->perms[option_indx].values;
		if (rowfits(towers, candidate, depth))
		{
			row_options->indx = option_indx;
			addto_mask(towers->colmask, candidate, towers->grid_size);
			if (!iscolclue_conflict(towers, depth))
			{
				if (col_search(towers, depth) == SOLVED)
					return (SOLVED);
			}
			rmfrom_mask(towers->colmask, candidate, towers->grid_size);
		}
		option_indx++;
	}
	return (UNSOLVED);
}

static int	col_search(t_towers *towers, int depth)
{
	int			option_indx;
	t_permlst	*col_options;
	int			*candidate;

	if (depth == towers->grid_size)
		return (SOLVED);
	option_indx = 0;
	col_options = &towers->col_options[depth];
	while (option_indx < col_options->size)
	{
		candidate = col_options->perms[option_indx].values;
		if (colfits(towers, candidate, depth))
		{
			col_options->indx = option_indx;
			addto_mask(towers->rowmask, candidate, towers->grid_size);
			if (!isrowclue_conflict(towers, depth))
			{
				if (row_search(towers, depth + 1) == SOLVED)
					return (SOLVED);
			}
			rmfrom_mask(towers->rowmask, candidate, towers->grid_size);
		}
		option_indx++;
	}
	return (UNSOLVED);
}

int	solve_towers(t_towers *towers)
{
	int	i;

	i = 0;
	while (i < towers->grid_size)
	{
		if (towers->row_options[i].size == 0
			|| towers->col_options[i].size == 0)
			return (UNSOLVED);
		i++;
	}
	return (row_search(towers, 0));
}
