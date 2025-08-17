/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isrightclue_conflict.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:06:01 by jchuah            #+#    #+#             */
/*   Updated: 2025/08/18 04:26:41 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	isrow_conflict_full(t_towers *towers, int rownum, int clue)
{
	t_permlst	*col_options;
	int			seen;
	int			max;
	int			view;
	int			i;

	col_options = towers->col_options;
	seen = 0;
	max = 0;
	i = towers->grid_size;
	while (i-- && max != towers->grid_size)
	{
		view = col_options[i].perms[col_options[i].indx].values[rownum];
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

static int	get_min_possible(t_towers *towers, int rownum, int depth)
{
	t_permlst	*col_options;
	int			min_possible;
	int			max;
	int			view;

	col_options = towers->col_options;
	max = get_max_unplaced(towers->rowmask[rownum], towers->grid_size);
	min_possible = 1;
	while (max < towers->grid_size)
	{
		view = col_options[depth].perms[col_options[depth].indx].values[rownum];
		if (max < view)
		{
			min_possible++;
			max = view;
		}
		depth--;
	}
	return (min_possible);
}

int	isrightclue_conflict(t_towers *towers, int depth)
{
	int	rownum;
	int	clue;
	int	min_possible;
	int	max_possible;

	rownum = depth + 1;
	while (rownum < towers->grid_size)
	{
		clue = towers->clues[towers->grid_size * 3 + rownum];
		if (depth == towers->grid_size - 1)
		{
			if (isrow_conflict_full(towers, rownum, clue))
				return (1);
		}
		else
		{
			min_possible = get_min_possible(towers, rownum, depth);
			max_possible = min_possible + (towers->grid_size - depth - 2);
			if (min_possible > clue || max_possible < clue)
				return (1);
		}
		rownum++;
	}
	return (0);
}
