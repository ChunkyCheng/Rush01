/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpadded.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:27:25 by jchuah            #+#    #+#             */
/*   Updated: 2025/05/29 13:29:19 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

//len is given as a parameter instead of strlen because len of str may not be
//the len of the whole output (in the case of %#0mx where m is the fwidth
//larger than length of the hex number)
//size is the number of pads to put, not the total characters to put
//str must have been malloc'd as function will free str
int	ft_putpadded(t_mods *mods, char *str, int len)
{
	char	pad;
	int		size;

	if (mods->flags & ZEROPAD)
		pad = '0';
	else
		pad = ' ';
	size = mods->fwidth - len;
	if (mods->flags & LEFTALIGN)
	{
		ft_putstr_fd(str, 1);
		while (size-- > 0)
			write(1, &pad, 1);
	}
	else
	{
		while (size-- > 0)
			write(1, &pad, 1);
		ft_putstr_fd(str, 1);
	}
	free(str);
	if (mods->fwidth > len)
		return (mods->fwidth);
	return (len);
}
