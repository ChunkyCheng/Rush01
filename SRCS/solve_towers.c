/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_towers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:31:35 by jchuah            #+#    #+#             */
/*   Updated: 2025/08/17 10:39:36 by jchuah           ###   ########.fr       */
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

static void	addto_usedmask(int *usedmask, int *candidate, int size)
{
	while (size--)
		usedmask[size] |= (1 << (candidate[size] - 1));
}

static void	rmfrom_usedmask(int *usedmask, int *candidate, int size)
{
	while (size--)
		usedmask[size] &= ~(1 << (candidate[size] - 1));
}

static int	isclue_conflict(t_towers *towers, int depth)
{
	if (istopclue_conflict(towers, depth))
		return (1);
	if (depth == towers->grid_size - 1
		&& isbotclue_conflict(towers))
		return (1);
	return (0);
}

static int	solution_search(t_towers *towers, int *usedmask, int depth)
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
		if (depth == 0 || !isplaced(candidate, usedmask, towers->grid_size))
		{
			options->indx = option_indx;
			addto_usedmask(usedmask, candidate, towers->grid_size);
			if (!isclue_conflict(towers, depth))
			{
				if (solution_search(towers, usedmask, depth + 1) == SOLVED)
					return (SOLVED);
			}
			rmfrom_usedmask(usedmask, candidate, towers->grid_size);
		}
		option_indx++;
	}
	return (UNSOLVED);
}

int	solve_towers(t_towers *towers)
{
	int	i;
	int	usedmask[GRID_SIZE_MAX];

	i = 0;
	while (i < towers->grid_size)
	{
		if (towers->row_options[i].size == 0)
			return (UNSOLVED);
		i++;
	}
	ft_bzero(usedmask, GRID_SIZE_MAX * sizeof(int));
	return (solution_search(towers, usedmask, 0));
}
