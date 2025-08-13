/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_uints.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:26:13 by jchuah            #+#    #+#             */
/*   Updated: 2025/05/29 13:31:46 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_uint(t_mods *mods, va_list args)
{
	t_ullong	num;

	num = (t_ullong)va_arg(args, unsigned int);
	mods->flags &= ~ALTFORM;
	return (put_uintf(mods, num, "0123456789", ""));
}

int	handle_hex(t_mods *mods, va_list args)
{
	t_ullong	num;

	num = (t_ullong)va_arg(args, unsigned int);
	if (num == 0)
		mods->flags &= ~ALTFORM;
	return (put_uintf(mods, num, "0123456789abcdef", "0x"));
}

int	handle_bighex(t_mods *mods, va_list args)
{
	t_ullong	num;

	num = (t_ullong)va_arg(args, unsigned int);
	if (num == 0)
		mods->flags &= ~ALTFORM;
	return (put_uintf(mods, num, "0123456789ABCDEF", "0X"));
}
