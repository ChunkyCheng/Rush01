/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_towers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:24:46 by jchuah            #+#    #+#             */
/*   Updated: 2025/08/16 17:22:59 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	free_towers(t_towers *towers)
{
	int	i;

	free(towers->perms);
	if (towers->row_options)
	{
		i = 0;
		while (i < towers->grid_size)
			free(towers->row_options[i++].perms);
	}
	free(towers->row_options);
	free(towers->clues);
}
