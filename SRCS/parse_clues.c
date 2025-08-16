/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_clues.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 16:31:51 by jchuah            #+#    #+#             */
/*   Updated: 2025/08/16 17:47:08 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

//returns non zero value on error
int	parse_clues(t_towers *towers, char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		towers->clues[i] = ft_atoi(argv[i]);
		if (towers->clues[i] > towers->grid_size)
		{
			ft_printf("Clue value of %d exceeds the grid size of %d\n",
				towers->clues[i], towers->grid_size);
			return (10);
		}
		if (towers->clues[i] <= 0)
		{
			ft_printf("Clue number %d is invalid\n", i + 1);
			return (11);
		}
		i++;
	}
	return (0);
}
