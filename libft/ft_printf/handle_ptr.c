/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:39:45 by jchuah            #+#    #+#             */
/*   Updated: 2025/05/29 14:52:03 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	handle_ptr(t_mods *mods, va_list args)
{
	t_ullong	num;
	char		*str;

	num = (t_ullong)va_arg(args, void *);
	mods->flags |= ALTFORM;
	if (num == 0)
	{
		str = "(nil)";
		mods->flags &= ~PRECISION;
		return (put_strf(mods, str));
	}
	return (put_uintf(mods, num, "0123456789abcdef", "0x"));
}
