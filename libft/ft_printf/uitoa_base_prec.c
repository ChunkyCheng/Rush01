/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitoa_base_prec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:22:57 by jchuah            #+#    #+#             */
/*   Updated: 2025/06/11 11:42:21 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char	*uitoa_base(t_ullong num, char *ref)
{
	char	temp[65];
	int		i;
	int		base;

	if (!ref)
		return (NULL);
	i = 64;
	temp[i] = '\0';
	base = ft_strlen(ref);
	while (num / base)
	{
		temp[--i] = ref[num % base];
		num /= base;
	}
	temp[--i] = ref[num % base];
	return (ft_strdup(&temp[i]));
}

char	*uitoa_base_prec(t_mods *mods, t_ullong num, char *ref)
{
	char	*str;
	int		len;
	char	*temp;

	if (mods->flags & PRECISION && mods->prec == 0 && num == 0)
		return (ft_strdup(""));
	str = uitoa_base(num, ref);
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if ((mods->flags & PRECISION) && mods->prec > len)
	{
		temp = (char *)malloc((mods->prec + 1) * sizeof(char));
		if (!temp)
		{
			free(str);
			return (NULL);
		}
		temp[mods->prec - len] = '\0';
		ft_memset(temp, '0', mods->prec - len);
		ft_strcat(temp, str);
		free(str);
		str = temp;
	}
	return (str);
}
