/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sioudare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 19:22:37 by sioudare          #+#    #+#             */
/*   Updated: 2016/07/16 19:22:39 by sioudare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"
#include "ft.h"

int		is_grid_valid(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (argc != 10)
		return (0);
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '\0')
			return (0);
		while (argv[i][j] != '\0')
		{
			if (!((argv[i][j] >= '1' && argv[i][j] <= '9') ||
				argv[i][j] == '.'))
				return (0);
			j++;
		}
		if (j != 9)
			return (0);
		i++;
	}
	return (1);
}

void	setup_grid(int argc, char **argv, char grid[9][9])
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			grid[i - 1][j] = argv[i][j];
			j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	char	grid[9][9];

	if (!(is_grid_valid(argc, argv)))
	{
		ft_putstr("Erreur\n");
		return (0);
	}
	setup_grid(argc, argv, grid);
	if (play_grid(grid, 0))
		print_sudoku(grid);
	else
		ft_putstr("Erreur\n");
	return (0);
}
