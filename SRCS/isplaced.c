/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isplaced.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 22:03:36 by jchuah            #+#    #+#             */
/*   Updated: 2025/08/18 01:42:00 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

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
