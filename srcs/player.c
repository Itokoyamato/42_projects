/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 13:28:33 by dthuilli          #+#    #+#             */
/*   Updated: 2017/06/11 17:15:04 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	do_play(t_data *env)
{
	ft_putnbr(env->play_pos.y);
	ft_putchar(' ');
	ft_putnbr(env->play_pos.x);
	ft_putchar('\n');
	if (env->stuck == 1)
		env->gamestate = 1;
	env->play_dir = 3 - env->play_dir;
	free_stuff(env);
}

int		try_piece_check(t_data *env, t_point p)
{
	int		wrong;
	t_point	p2;

	wrong = 0;
	p2.y = 0;
	while (p2.y < env->piece_size.y)
	{
		p2.x = 0;
		while (p2.x < env->piece_size.x)
		{
			if (env->piece[p2.y][p2.x] == '*')
			{
				if (env->map[p.y + p2.y][p.x + p2.x] == env->local_p_char ||
					env->map[p.y + p2.y][p.x + p2.x] == env->local_p_char + 32)
					++wrong;
				if (env->map[p.y + p2.y][p.x + p2.x] == env->p_char ||
					env->map[p.y + p2.y][p.x + p2.x] == env->p_char + 32)
					return (0);
			}
			++p2.x;
		}
		++p2.y;
	}
	return ((wrong == 1) ? 1 : 0);
}

int		try_piece(t_data *env, t_point p)
{
	if (p.y + env->piece_size.y > env->map_size.y)
		return (0);
	if (p.x + env->piece_size.x > env->map_size.x)
		return (0);
	return (try_piece_check(env, p));
}

int		try_position(t_data *env, int move_x_way, int move_y_way)
{
	t_point	p;

	p.y = (move_y_way > 0) ? 0 : env->map_size.y;
	while (p.y <= env->map_size.y && p.y >= 0)
	{
		p.x = (move_x_way > 0) ? 0 : env->map_size.x;
		while (p.x <= env->map_size.x && p.x >= 0)
		{
			if (try_piece(env, p) == 1)
			{
				env->play_pos.x = p.x;
				env->play_pos.y = p.y;
				return (1);
			}
			p.x = p.x + (move_x_way);
		}
		p.y = p.y + (move_y_way);
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
