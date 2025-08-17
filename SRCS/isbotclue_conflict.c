/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isbotclue_conflict.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:06:01 by jchuah            #+#    #+#             */
/*   Updated: 2025/08/18 02:27:17 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	iscol_conflict_full(t_towers *towers, int colnum, int clue)
{
	t_permlst	*row_options;
	int			seen;
	int			max;
	int			view;
	int			i;

	row_options = towers->row_options;
	seen = 0;
	max = 0;
	i = towers->grid_size;
	while (i-- && max != towers->grid_size)
	{
		view = row_options[i].perms[row_options[i].indx].values[colnum];
		if (max < view)
		{
			seen++;
			max = view;
		}
	}
	if (seen != clue)
		return (1);
	return (0);
}

static int	get_max_unplaced(int mask, int size)
{
	int	num;
	int	i;

	num = size;
	i = 1 << (size - 1);
	while (i & mask)
	{
		num--;
		i >>= 1;
	}
	return (num);
}

static int	get_min_possible(t_towers *towers, int colnum, int depth)
{
	t_permlst	*row_options;
	int			min_possible;
	int			max;
	int			view;

	row_options = towers->row_options;
	max = get_max_unplaced(towers->colmask[colnum], towers->grid_size);
	min_possible = 1;
	while (max < towers->grid_size)
	{
		view = row_options[depth].perms[row_options[depth].indx].values[colnum];
		if (max < view)
		{
			min_possible++;
			max = view;
		}
		depth--;
	}
	return (min_possible);
}

int	isbotclue_conflict(t_towers *towers, int depth)
{
	int	colnum;
	int	clue;
	int	min_possible;
	int	max_possible;

	colnum = 0;
	while (colnum < towers->grid_size)
	{
		clue = towers->clues[towers->grid_size + colnum];
		if (depth == towers->grid_size - 1)
		{
			if (iscol_conflict_full(towers, colnum, clue))
				return (1);
		}
		else
		{
			min_possible = get_min_possible(towers, colnum, depth);
			max_possible = min_possible + (towers->grid_size - depth - 2);
			if (min_possible > clue || max_possible < clue)
				return (1);
		}
		colnum++;
	}
	return (0);
}
