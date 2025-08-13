/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jchuah@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 09:14:18 by jchuah            #+#    #+#             */
/*   Updated: 2025/08/13 14:24:58 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

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

static int	get_grid_size(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

static void	free_rush01(char **argv, int *grid, int *clues)
{
	char	**origin;

	origin = argv;
	while (*argv)
		free(*argv++);
	free(origin);
	free(grid);
	free(clues);
}

int	main(int argc, char *argv[])
{
	int	clue_count;
	int	*grid;
	int	*clues;

	if (argc != 2)
	{
		return (ft_printf("Usage: %s <clues> (\"<colup> ... <coldown> ... "
				"<rowleft> ... <rowright> ...\")\n", argv[0]) * 0 + 1);
	}
	if (!integer_check(argv[1]))
		return (ft_printf("All clues must be positive integers\n") * 0 + 2);
	argv = ft_split(argv[1], " \t\n");
	if (!argv)
		return (ft_printf("Memory allocation error\n") * 0 + 3);
	clue_count = get_grid_size(argv);
	if (clue_count == 0 || (clue_count % 4) != 0)
		return (ft_printf("Clue count  must be a multiple of 4\n") * 0 + 4);
	grid = (int *)malloc(clue_count * clue_count / 16 * sizeof(int));
	clues = (int *)malloc(clue_count * sizeof(int));
	if (!clues || !grid)
	{
		free_rush01(argv, grid, clues);
		return (ft_printf("Memory allocation error\n") * 0 + 3);
	}
	free_rush01(argv, grid, clues);
}
