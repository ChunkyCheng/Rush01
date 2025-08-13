/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_uintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:43:02 by jchuah            #+#    #+#             */
/*   Updated: 2025/06/08 16:57:22 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	put_uintf(t_mods *mods, t_ullong num, char *ref, char *altprfx)
{
	char	*str;
	char	*temp;
	int		len;

	str = uitoa_base_prec(mods, num, ref);
	if (!str)
		return (-1);
	if ((mods->flags & ALTFORM) && !(mods->flags & ZEROPAD))
	{
		temp = ft_strjoin(altprfx, str);
		free(str);
		str = temp;
	}
	if (!str)
		return (-1);
	len = ft_strlen(str);
	if ((mods->flags & ALTFORM) && (mods->flags & ZEROPAD))
		len += ft_putstr_fd(altprfx, 1);
	return (ft_putpadded(mods, str, len));
}
