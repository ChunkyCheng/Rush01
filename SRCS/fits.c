/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 04:07:14 by jchuah            #+#    #+#             */
/*   Updated: 2025/08/18 04:24:26 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	rowfits(t_towers *towers, int *candidate, int depth)
{
	t_permlst	*col_options;
	int			i;
	int			current;

	if (depth == 0)
		return (1);
	if (isplaced(towers->colmask, candidate, towers->grid_size))
		return (0);
	col_options = towers->col_options;
	i = 0;
	while (i < depth)
	{
		current = col_options[i].perms[col_options[i].indx].values[depth];
		if (candidate[i] != current)
			return (0);
		i++;
	}
	return (1);
}

int	colfits(t_towers *towers, int *candidate, int depth)
{
	t_permlst	*row_options;
	int			i;
	int			current;

	if (isplaced(towers->rowmask, candidate, towers->grid_size))
		return (0);
	row_options = towers->row_options;
	i = 0;
	while (i <= depth)
	{
		current = row_options[i].perms[row_options[i].indx].values[depth];
		if (candidate[i] != current)
			return (0);
		i++;
	}
	return (1);
}
