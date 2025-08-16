/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_towers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:31:35 by jchuah            #+#    #+#             */
/*   Updated: 2025/08/16 20:35:54 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

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
	return (SOLVED);
}
