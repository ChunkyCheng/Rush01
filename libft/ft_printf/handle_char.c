/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 09:42:54 by jchuah            #+#    #+#             */
/*   Updated: 2025/05/29 12:57:57 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	handle_char(t_mods *mods, va_list args)
{
	char	c;
	int		len;

	c = (unsigned char)va_arg(args, int);
	len = mods->fwidth - 1;
	if (mods->flags & LEFTALIGN)
	{
		write(1, &c, 1);
		while (len-- > 0)
			write(1, " ", 1);
	}
	else
	{
		while (len-- > 0)
			write(1, " ", 1);
		write(1, &c, 1);
	}
	if (mods->fwidth > 1)
		return (mods->fwidth);
	return (1);
}
