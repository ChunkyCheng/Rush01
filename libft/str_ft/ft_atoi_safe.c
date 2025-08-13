/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 17:01:58 by jchuah            #+#    #+#             */
/*   Updated: 2025/07/18 19:08:22 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

int	ft_atoi_safe(const char *nptr, int *dst)
{
	int	sign;

	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	sign = 1;
	if (*nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	*dst = 0;
	while (ft_isdigit(*nptr))
	{
		if ((sign == 1 && *dst > (INT_MAX - (*nptr - '0')) / 10)
			|| (sign == -1 && *dst < (INT_MIN + (*nptr - '0')) / 10))
			return (0);
		*dst *= 10;
		*dst += (*nptr - '0') * sign;
		nptr++;
	}
	return (1);
}
