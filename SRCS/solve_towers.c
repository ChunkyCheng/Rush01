/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_towers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:31:35 by jchuah            #+#    #+#             */
/*   Updated: 2025/08/18 03:32:53 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

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

static void	addto_mask(int *mask, int *candidate, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		mask[i] |= (1 << (candidate[i] - 1));
		i++;
	}
}

static void	rmfrom_mask(int *mask, int *candidate, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		mask[i] &= ~(1 << (candidate[i] - 1));
		i++;
	}
}

static int	isclue_conflict(t_towers *towers, int depth)
{
	if (istopclue_conflict(towers, depth))
		return (1);
	if (isbotclue_conflict(towers, depth))
		return (1);
	return (0);
}

static int	solution_search(t_towers *towers, int depth)
{
	int			option_indx;
	t_permlst	*options;
	int			*candidate;

	if (depth == towers->grid_size)
		return (SOLVED);
	option_indx = 0;
	options = &towers->row_options[depth];
	while (option_indx < options->size)
	{
		candidate = options->perms[option_indx].values;
		if (!isplaced(towers->colmask, candidate, towers->grid_size))
		{
			options->indx = option_indx;
			addto_mask(towers->colmask, candidate, towers->grid_size);
			if (!isclue_conflict(towers, depth))
			{
				if (solution_search(towers, depth + 1) == SOLVED)
					return (SOLVED);
			}
			rmfrom_mask(towers->colmask, candidate, towers->grid_size);
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
		if (towers->row_options[i].size == 0)
			return (UNSOLVED);
		i++;
	}
	return (solution_search(towers, 0));
}
