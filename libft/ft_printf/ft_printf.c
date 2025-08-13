/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:28:27 by jchuah            #+#    #+#             */
/*   Updated: 2025/06/08 17:29:59 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdio.h>

static int	get_flag(const char flag, unsigned int *flags)
{
	char	*flaglist;
	int		flagvals[256];

	flaglist = "#0- +";
	if (!flag || !ft_strchr(flaglist, flag))
		return (0);
	flagvals['#'] = ALTFORM;
	flagvals['0'] = ZEROPAD;
	flagvals['-'] = LEFTALIGN;
	flagvals[' '] = ADDSPACE;
	flagvals['+'] = SHOWSIGN;
	*flags |= flagvals[(int)flag];
	return (1);
}

static t_mods	init_flags(const char **format)
{
	t_mods			mods;

	mods.flags = 0;
	while (get_flag(*(*format), &mods.flags))
		(*format)++;
	mods.fwidth = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
	if (**format == '.')
	{
		(*format)++;
		mods.prec = ft_atoi(*format);
		if (mods.prec >= 0)
			mods.flags |= PRECISION;
		while (ft_isdigit(**format))
			(*format)++;
	}
	if ((mods.flags & LEFTALIGN) || (mods.flags & PRECISION))
		mods.flags &= ~ZEROPAD;
	return (mods);
}

static t_handler	get_handler(const char spec)
{
	char		*speclist;
	t_handler	handlers[256];

	speclist = "cspdiuxX%";
	if (!spec || !ft_strchr(speclist, spec))
		return (NULL);
	handlers['c'] = handle_char;
	handlers['s'] = handle_str;
	handlers['p'] = handle_ptr;
	handlers['d'] = handle_int;
	handlers['i'] = handle_int;
	handlers['u'] = handle_uint;
	handlers['x'] = handle_hex;
	handlers['X'] = handle_bighex;
	handlers['%'] = handle_percent;
	return (handlers[(int)spec]);
}

//Returns number of characters printed if conversion character is found
//Returns -1 on error
static int	handle_conversion(const char **format, va_list args)
{
	const char	*origin;
	t_mods		mods;
	t_handler	handler;

	origin = *format;
	mods = init_flags(format);
	handler = get_handler(*(*format)++);
	if (handler)
		return (handler(&mods, args));
	write(1, "%", 1);
	*format = origin;
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		count;	

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format != '%')
			len += write(1, format++, 1);
		else
		{
			format++;
			count = handle_conversion(&format, args);
			if (count < 0)
			{
				va_end(args);
				return (-1);
			}
			len += count;
		}
	}
	va_end(args);
	return (len);
}
