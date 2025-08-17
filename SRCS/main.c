/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:14:18 by jchuah            #+#    #+#             */
/*   Updated: 2025/08/16 23:59:07 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

/*
static void	print_perms(t_towers *towers)
{
	int		i;
	int		j;
	t_perm	*perms;

	i = 0;
	perms = towers->perms;
	ft_printf("%d permutations\n", towers->perm_count);
	while (i < towers->perm_count)
	{
		j = 0;
		ft_printf("{ ");
		while (j < towers->grid_size)
			ft_printf("%d ", perms[i].values[j++]);
		ft_printf("}, left vis: %d, right vis: %d\n",
			perms[i].left_vis, perms[i].right_vis);
		i++;
	}
}
*/

void	print_towers(t_towers *towers)
{
	int			i;
	int			j;
	t_permlst	row_options;
	int			*row;

	i = 0;
	while (i < towers->grid_size)
	{
		row_options = towers->row_options[i];
		if (row_options.indx >= row_options.size)
			ft_printf("(null)\n");
		else
		{
			row = row_options.perms[row_options.indx].values;
			j = 0;
			while (j < towers->grid_size - 1)
				ft_printf("%d ", row[j++]);
			ft_printf("%d\n", row[j]);
		}
		i++;
	}
}

static int	integer_check(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && !ft_strchr(" \t\n", *str))
			return (0);
		str++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int			errorcode;
	t_towers	towers;

	if (argc != 2)
	{
		return (ft_printf("Usage: %s <clues> (\"<colup> ... <coldown> ... "
				"<rowleft> ... <rowright> ...\")\n", argv[0]) * 0 + 1);
	}
	if (!integer_check(argv[1]))
		return (ft_printf("All clues must be positive integers\n") * 0 + 2);
	errorcode = initialise_towers(argv, &towers);
	if (errorcode != 0)
		return (errorcode);
	generate_perms(&towers);
	errorcode = find_row_options(&towers);
	if (errorcode != 0)
		return (errorcode);
	if (solve_towers(&towers) == SOLVED)
		print_towers(&towers);
	else
		ft_printf("No solution found\n");
	free_towers(&towers);
	return (0);
}
