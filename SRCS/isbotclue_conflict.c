/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isbotclue_conflict.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:06:01 by jchuah            #+#    #+#             */
/*   Updated: 2025/08/16 23:02:38 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	iscol_conflict(t_towers *towers, int colnum, int clue)
{
	t_permlst	*row_options;
	int			seen;
	int			max;
	int			current;
	int			i;

	row_options = towers->row_options;
	seen = 0;
	max = 0;
	i = towers->grid_size;
	while (i-- && max != towers->grid_size)
	{
		current = row_options[i].perms[row_options[i].indx].values[colnum];
		if (max < current)
		{
			seen++;
			max = current;
		}
	}
	if (seen != clue)
		return (1);
	return (0);
}

int	isbotclue_conflict(t_towers *towers)
{
	int	colnum;
	int	clue;

	colnum = 0;
	while (colnum < towers->grid_size)
	{
		clue = towers->clues[towers->grid_size + colnum];
		if (iscol_conflict(towers, colnum, clue))
			return (1);
		colnum++;
	}
	return (0);
}
