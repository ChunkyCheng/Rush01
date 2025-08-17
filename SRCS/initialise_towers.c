/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_towers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:24:46 by jchuah            #+#    #+#             */
/*   Updated: 2025/08/18 03:33:48 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	count_clues(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

static void	free_double_array(char **argv)
{
	char	**origin;

	origin = argv;
	while (*argv)
		free(*argv++);
	free(origin);
}

static int	malloc_towers(t_towers *towers, char **argv)
{
	int	clue_count;
	int	grid_size;
	int	i;

	clue_count = count_clues(argv);
	if (clue_count > GRID_SIZE_MAX * 4)
		return (ft_printf("Max clue count is %d\n", GRID_SIZE_MAX * 4) * 0 + 5);
	if (clue_count == 0 || (clue_count % 4) != 0)
		return (ft_printf("Clue count  must be a multiple of 4\n") * 0 + 4);
	grid_size = clue_count / 4;
	towers->perm_count = 1;
	i = grid_size;
	while (i > 1)
	{
		towers->perm_count *= i;
		i--;
	}
	towers->perms = (t_perm *)malloc(towers->perm_count * sizeof(t_perm));
	ft_bzero(towers->row_options, grid_size * sizeof(t_permlst));
	ft_bzero(towers->col_options, grid_size * sizeof(t_permlst));
	towers->clues = (int *)malloc(clue_count * sizeof(int));
	ft_bzero(towers->colmask, grid_size * sizeof(int));
	ft_bzero(towers->rowmask, grid_size * sizeof(int));
	towers->grid_size = grid_size;
	return (0);
}

//returns zero on success
//returns non zero value for exit code in case of error
//frees approprite memory on error
int	initialise_towers(char **argv, t_towers *towers)
{
	int	errorcode;

	argv = ft_split(argv[1], " \t\n");
	if (!argv)
		return (ft_printf("Memory allocation error\n") * 0 + 3);
	errorcode = malloc_towers(towers, argv);
	if (errorcode != 0)
	{
		free_double_array(argv);
		return (errorcode);
	}
	if (!towers->perms || !towers->clues)
	{
		free_double_array(argv);
		free_towers(towers);
		return (ft_printf("Memory allocation error\n") * 0 + 3);
	}
	errorcode = parse_clues(towers, argv);
	free_double_array(argv);
	if (errorcode != 0)
	{
		free_towers(towers);
		return (errorcode);
	}
	return (0);
}
