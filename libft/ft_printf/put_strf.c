/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_strf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:45:58 by jchuah            #+#    #+#             */
/*   Updated: 2025/05/29 12:07:56 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	put_strf(t_mods *mods, char *str)
{
	int	len;

	if (mods->flags & PRECISION)
		str = ft_substr(str, 0, mods->prec);
	else
		str = ft_strdup(str);
	if (!str)
		return (-1);
	len = ft_strlen(str);
	return (ft_putpadded(mods, str, len));
}
