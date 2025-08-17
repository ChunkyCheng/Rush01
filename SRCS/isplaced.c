/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isplaced.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:03:36 by jchuah            #+#    #+#             */
/*   Updated: 2025/08/16 22:46:04 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	isplaced(int *candidate, int *usedmask, int size)
{
	while (size--)
	{
		if (usedmask[size] & (1 << (candidate[size] - 1)))
			return (1);
	}
	return (0);
}
