/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_option_matches.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 18:35:51 by jchuah            #+#    #+#             */
/*   Updated: 2025/08/18 03:01:46 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	fill_matches(t_towers *towers, t_perm *options,
int clue1, int clue2)
{
	t_perm	*fullperms;
	int		i;
	int		option_indx;

	fullperms = towers->perms;
	i = 0;
	option_indx = 0;
	while (i < towers->perm_count)
	{
		if (clue1 == fullperms[i].left_vis
			&& clue2 == fullperms[i].right_vis)
		{
			options[option_indx] = fullperms[i];
			option_indx++;
		}
		i++;
	}
}
