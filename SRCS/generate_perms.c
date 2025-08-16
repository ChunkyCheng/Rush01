/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_perms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:09:39 by jchuah            #+#    #+#             */
/*   Updated: 2025/08/16 18:30:49 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	count_left_visible(int *array, int size)
{
	int	count;
	int	i;
	int	max;

	count = 0;
	i = 0;
	max = 0;
	while (i < size && max != size)
	{
		if (array[i] > max)
		{
			count++;
			max = array[i];
		}
		i++;
	}
	return (count);
}

static int	count_right_visible(int *array, int size)
{
	int	count;
	int	max;
	int	i;

	count = 0;
	max = 0;
	i = size;
	while (i-- && max != size)
	{
		if (array[i] > max)
		{
			count++;
			max = array[i];
		}
	}
	return (count);
}

static int	isused(int num, int *temp, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (num == temp[i])
			return (1);
		i++;
	}
	return (0);
}

static void	fill_perms(t_towers *towers, int *temp, int *permindx, int tempindx)
{
	int		grid_size;
	t_perm	*perms;
	int		num;

	grid_size = towers->grid_size;
	perms = towers->perms;
	if (tempindx == grid_size)
	{
		ft_memcpy(perms[*permindx].values, temp, grid_size * sizeof(int));
		perms[*permindx].left_vis = count_left_visible(temp, grid_size);
		perms[*permindx].right_vis = count_right_visible(temp, grid_size);
		(*permindx)++;
		return ;
	}
	num = 1;
	while (num <= grid_size)
	{
		if (!isused(num, temp, tempindx))
		{
			temp[tempindx] = num;
			fill_perms(towers, temp, permindx, tempindx + 1);
		}
		num++;
	}
}

void	generate_perms(t_towers *towers)
{
	int	temp[GRID_SIZE_MAX];
	int	permindx;

	permindx = 0;
	fill_perms(towers, temp, &permindx, 0);
}
