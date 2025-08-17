/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usedmask.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:31:35 by jchuah            #+#    #+#             */
/*   Updated: 2025/08/18 03:49:57 by jchuah           ###   ########.fr       */
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

void	addto_mask(int *mask, int *candidate, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		mask[i] |= (1 << (candidate[i] - 1));
		i++;
	}
}

void	rmfrom_mask(int *mask, int *candidate, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		mask[i] &= ~(1 << (candidate[i] - 1));
		i++;
	}
}

int	isplaced(int *mask, int *candidate, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (mask[i] & (1 << (candidate[i] - 1)))
			return (1);
		i++;
	}
	return (0);
}
