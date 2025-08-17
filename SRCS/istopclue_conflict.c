/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   istopclue_conflict.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:06:01 by jchuah            #+#    #+#             */
/*   Updated: 2025/08/17 00:01:33 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	isclue_conflict(int seen, int clue, int max, int grid_size)
{
	if (max == grid_size && seen != clue)
		return (1);
	if (seen > clue)
		return (1);
	if (max < grid_size && seen + 1 > clue)
		return (1);
	if (seen < clue - (grid_size - max))
		return (1);
	return (0);
}

static int	iscol_conflict(t_towers *towers, int colnum, int depth, int clue)
{
	t_permlst	*row_options;
	int			seen;
	int			max;
	int			current;
	int			i;

	row_options = towers->row_options;
	seen = 0;
	max = 0;
	i = 0;
	while (i <= depth && max != towers->grid_size)
	{
		current = row_options[i].perms[row_options[i].indx].values[colnum];
		if (max < current)
		{
			seen++;
			max = current;
		}
		i++;
	}
	if ((depth == towers->grid_size - 1 && seen != clue)
		|| isclue_conflict(seen, clue, max, towers->grid_size)
		|| seen < clue - (towers->grid_size - depth))
		return (1);
	return (0);
}

int	istopclue_conflict(t_towers *towers, int depth)
{
	int	colnum;
	int	clue;

	colnum = 0;
	while (colnum < towers->grid_size)
	{
		clue = towers->clues[colnum];
		if (iscol_conflict(towers, colnum, depth, clue))
			return (1);
		colnum++;
	}
	return (0);
}
