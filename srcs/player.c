/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 13:28:33 by dthuilli          #+#    #+#             */
/*   Updated: 2017/06/10 13:35:11 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	do_play(t_data *env)
{
	env->play_dir = 3 - env->play_dir;
	if (env->stuck == 1)
	{
		env->gamestate = 1;
		ft_putnbr(env->play_y);
		ft_putchar(' ');
		ft_putnbr(env->play_x);
		ft_putchar('\n');
	}
	else
	{
		ft_putnbr(env->play_y);
		ft_putchar(' ');
		ft_putnbr(env->play_x);
		ft_putchar('\n');
	}
}

int		try_piece_check(t_data *env, int y, int x)
{
	int		wrong;
	int		x2;
	int		y2;

	wrong = 0;
	y2 = 0;
	while (y2 < env->piece_size_y)
	{
		x2 = 0;
		while (x2 < env->piece_size_x)
		{
			if (env->piece[y2][x2] == '*')
			{
				if (env->map[y + y2][x + x2] == env->local_playerchar ||
						env->map[y + y2][x + x2] == env->local_playerchar + 32)
					++wrong;
				if (env->map[y + y2][x + x2] == env->playerchar ||
						env->map[y + y2][x + x2] == env->playerchar + 32)
					return (0);
			}
			++x2;
		}
		++y2;
	}
	return ((wrong == 1) ? 1 : 0);
}

int		try_piece(t_data *env, int y, int x)
{
	if (y + env->piece_size_y > env->map_size_y)
		return (0);
	if (x + env->piece_size_x > env->map_size_x)
		return (0);
	return (try_piece_check(env, y, x));
}

int		try_position(t_data *env, int move_x_way, int move_y_way)
{
	int		y;
	int		x;

	y = (move_y_way > 0) ? 0 : env->map_size_y;
	while (y <= env->map_size_y && y >= 0)
	{
		x = (move_x_way > 0) ? 0 : env->map_size_x;
		while (x <= env->map_size_x && x >= 0)
		{
			if (try_piece(env, y, x) == 1)
			{
				env->play_x = x;
				env->play_y = y;
				return (1);
			}
			x = x + (move_x_way);
		}
		y = y + (move_y_way);
	}
	return (0);
}

int		do_solve(t_data *env)
{
	int		result;

	result = 0;
	if (env->play_dir == 0)
		result = try_position(env, 1, 1);
	else if (env->play_dir == 1)
		result = try_position(env, -1, -1);
	else if (env->play_dir == 2)
		result = try_position(env, -1, 1);
	else if (env->play_dir == 3)
		result = try_position(env, 1, -1);
	return (result);
}
