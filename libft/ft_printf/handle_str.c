/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:30:10 by jchuah            #+#    #+#             */
/*   Updated: 2025/06/08 16:51:33 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_str(t_mods *mods, va_list args)
{
	char	*str;

	str = (char *)va_arg(args, const char *);
	mods->flags &= ~ZEROPAD;
	if (!str)
	{
		if (mods->flags & PRECISION && mods->prec < 6)
			str = "";
		else
			str = "(null)";
		mods->flags &= ~PRECISION;
	}
	return (put_strf(mods, str));
}
