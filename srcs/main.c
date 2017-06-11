/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 17:55:59 by dthuilli          #+#    #+#             */
/*   Updated: 2017/06/11 11:50:43 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	retrieve_piece(t_data *env, char *gnl)
{
	t_point p;

	p.x = 6;
	p.y = 0;
	env->piece_size.y = ft_atoi(&gnl[6]);
	while (ft_isdigit(gnl[p.x]))
		++p.x;
	++p.x;
	env->piece_size.x = ft_atoi(&gnl[p.x]);
	if (!env->piece)
		env->piece = ft_memalloc(sizeof(char *) * env->piece_size.y);
	while (p.y < env->piece_size.y)
	{
		get_next_line(0, &gnl);
		if (!env->piece[p.y])
			env->piece[p.y] = ft_memalloc(sizeof(char *) * env->piece_size.x);
		env->piece[p.y] = ft_strdup(gnl);
		++p.y;
	}
}

void	retrieve_player_data(t_data *env)
{
	t_point		p;

	p.y = 0;
	env->p_char = (env->local_p_char == 'O') ? 'X' : 'O';
	while (p.y < env->map_size.y)
	{
		p.x = 0;
		while (p.x < env->map_size.x)
		{
			if (env->map[p.y][p.x] == env->p_char)
			{
				env->player_pos.x = p.x;
				env->player_pos.y = p.y;
			}
			if (env->map[p.y][p.x] == env->local_p_char)
			{
				env->local_pos.x = p.x;
				env->local_pos.y = p.y;
			}
			++p.x;
		}
		++p.y;
	}
	env->play_dir = (env->player_pos.y > env->local_pos.y) ? 1 : 0;
}

void	retrieve_data(t_data *env)
{
	char	*gnl;
	int		i;

	i = 0;
	if (!env->map)
		env->map = ft_memalloc(sizeof(char *) * env->map_size.y);
	get_next_line(0, &gnl);
	while (i <= env->map_size.y)
	{
		get_next_line(0, &gnl);
		if (ft_isdigit(gnl[0]))
		{
			if (!env->map[i])
				env->map[i] = ft_memalloc(sizeof(char *) * env->map_size.x);
			env->map[i] = ft_strdup(gnl + 4);
		}
		else
			retrieve_piece(env, gnl);
		++i;
	}
	if (env->player_pos.x == 0 && env->player_pos.y == 0 &&
		env->local_pos.x == 0 && env->local_pos.y == 0)
		retrieve_player_data(env);
}

void	game_end(t_data *env)
{
	free(env->map);
	free(env->piece);
	free(env);
}

int		main(void)
{
	char	*gnl;
	t_data	*env;

	if (!(env = ft_memalloc(sizeof(t_data))))
		return (-1);
	get_next_line(0, &gnl);
	env->local_p_char = (ft_atoi(gnl + 10) == 1) ? 'O' : 'X';
	while (1)
	{
		get_next_line(0, &gnl);
		env->map_size.y = ft_atoi(&gnl[8]);
		env->map_size.x = ft_atoi(&gnl[11]);
		retrieve_data(env);
		if (do_solve(env) == 0)
			env->stuck = 1;
		do_play(env);
		if (env->gamestate == 1)
		{
			game_end(env);
			break ;
		}
	}
	return (0);
}
