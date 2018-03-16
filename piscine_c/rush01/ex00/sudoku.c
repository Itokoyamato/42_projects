/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 10:57:20 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/17 19:33:29 by grleblan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		is_number_used_square(char grid[9][9], int test_value, int i, int j)
{
	int		bloc_i;
	int		bloc_j;

	bloc_i = 3 * (i / 3);
	bloc_j = 3 * (j / 3);
	i = bloc_i;
	j = bloc_j;
	while (i < bloc_i + 3)
	{
		j = bloc_j;
		while (j < bloc_j + 3)
		{
			if (grid[i][j] == test_value)
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int		is_number_used_column(char grid[9][9], int test_value, int j)
{
	int		i;

	i = 1;
	while (i <= 9)
	{
		if (grid[i][j] == test_value)
			return (0);
		i++;
	}
	return (1);
}

int		is_number_used_line(char grid[9][9], int test_value, int i)
{
	int		j;

	j = 0;
	while (j < 9)
	{
		if (grid[i][j] == test_value)
			return (0);
		j++;
	}
	return (1);
}

int		play_grid(char grid[9][9], int current_position)
{
	int		i;
	int		j;
	int		test_value;

	if (current_position == 9 * 9)
		return (1);
	test_value = '1';
	i = current_position / 9;
	j = current_position % 9;
	if (grid[i][j] != '.')
		return (play_grid(grid, current_position + 1));
	while (test_value <= '9')
	{
		if (is_number_used_line(grid, test_value, i) &&
			is_number_used_column(grid, test_value, j) &&
			is_number_used_square(grid, test_value, i, j))
		{
			grid[i][j] = test_value;
			if (play_grid(grid, current_position + 1))
				return (1);
		}
		test_value++;
	}
	grid[i][j] = '.';
	return (0);
}

void	print_sudoku(char grid[9][9])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			ft_putchar(grid[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
