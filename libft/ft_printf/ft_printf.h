/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:15:34 by jchuah            #+#    #+#             */
/*   Updated: 2025/05/29 13:37:41 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

//Flag macros
# define ALTFORM	0b1
# define ZEROPAD	0b10
# define LEFTALIGN	0b100
# define ADDSPACE	0b1000
# define SHOWSIGN	0b10000
# define PRECISION	0b100000

typedef unsigned long long	t_ullong;
typedef long long			t_llong;

typedef struct s_mods
{
	unsigned int	flags;
	int				fwidth;
	int				prec;
}	t_mods;

//The printf
int		ft_printf(const char *format, ...);

//handler functions that will go into an array of function pointers
//each handles a conversion specifier
typedef int					(*t_handler)(t_mods *mods, va_list args);
int		handle_char(t_mods *mods, va_list args);
int		handle_str(t_mods *mods, va_list args);
int		handle_ptr(t_mods *mods, va_list args);
int		handle_int(t_mods *mods, va_list args);
int		handle_uint(t_mods *mods, va_list args);
int		handle_hex(t_mods *mods, va_list args);
int		handle_bighex(t_mods *mods, va_list args);
int		handle_percent(t_mods *mods, va_list args);

//helpers that are common between handlers
int		ft_putpadded(t_mods *mods, char *str, int len);
int		put_strf(t_mods *mods, char *str);
char	*uitoa_base_prec(t_mods *mods, t_ullong num, char *ref);
int		put_uintf(t_mods *mods, t_ullong num, char *ref, char *altprfx);

#endif
