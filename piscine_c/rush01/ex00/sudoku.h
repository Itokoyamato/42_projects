/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sioudare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 19:24:14 by sioudare          #+#    #+#             */
/*   Updated: 2016/07/16 19:24:16 by sioudare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

int		is_number_used_square(char grid[9][9], int test_value, int i, int j);
int		is_number_used_column(char grid[9][9], int test_value, int j);
int		is_number_used_line(char grid[9][9], int test_value, int i);
int		play_grid(char grid[9][9], int current_position);
void	print_sudoku(char grid[9][9]);
#endif
