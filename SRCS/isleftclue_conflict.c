/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isleftclue_conflict.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:06:01 by jchuah            #+#    #+#             */
/*   Updated: 2025/08/18 03:41:44 by jchuah           ###   ########.fr       */
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

static int	isrow_conflict(t_towers *towers, int rownum, int depth, int clue)
{
	t_permlst	*col_options;
	int			seen;
	int			max;
	int			current;
	int			i;

	col_options = towers->col_options;
	seen = 0;
	max = 0;
	i = 0;
	while (i <= depth && max != towers->grid_size)
	{
		current = col_options[i].perms[col_options[i].indx].values[rownum];
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

int	isleftclue_conflict(t_towers *towers, int depth)
{
	int	rownum;
	int	clue;

	rownum = depth + 1;
	while (rownum < towers->grid_size)
	{
		clue = towers->clues[towers->grid_size * 2 + rownum];
		if (isrow_conflict(towers, rownum, depth, clue))
			return (1);
		rownum++;
	}
	return (0);
}
