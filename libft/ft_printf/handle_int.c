/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:34:56 by jchuah            #+#    #+#             */
/*   Updated: 2025/06/08 17:33:06 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*itoa_base(t_mods *mods, t_llong num, char *ref, char *prfx)
{
	t_ullong	abs;
	char		*str;
	char		*temp;

	if (num < 0)
		abs = (t_ullong)(num * -1);
	else
		abs = (t_ullong)num;
	str = uitoa_base_prec(mods, abs, ref);
	if (!(mods->flags & ZEROPAD))
	{
		temp = ft_strjoin(prfx, str);
		free(str);
		str = temp;
	}
	return (str);
}

static int	put_intf_base(t_mods *mods, t_llong num, char *ref)
{
	char	*str;
	int		len;
	char	*prfx;

	if (num < 0)
		prfx = "-";
	else if (mods->flags & SHOWSIGN)
		prfx = "+";
	else if (mods->flags & ADDSPACE)
		prfx = " ";
	else
		prfx = "";
	str = itoa_base(mods, num, ref, prfx);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	if ((mods->flags & ZEROPAD) && *prfx)
		len += write(1, prfx, 1);
	return (ft_putpadded(mods, str, len));
}

int	handle_int(t_mods *mods, va_list args)
{
	t_llong	num;

	num = (t_llong)va_arg(args, int);
	return (put_intf_base(mods, num, "0123456789"));
}
