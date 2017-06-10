/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 17:55:59 by dthuilli          #+#    #+#             */
/*   Updated: 2017/06/10 13:28:15 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "stdio.h"

void	retrieve_piece(t_data *env, char *gnl)
{
	int		n;
	int		i;

	n = 6;
	i = 0;
	env->piece_size_y = ft_atoi(&gnl[6]);
	while (ft_isdigit(gnl[n]))
		n++;
	n++;
	env->piece_size_x = ft_atoi(&gnl[n]);
	if (!env->piece)
		env->piece = ft_memalloc(sizeof(char *) * env->piece_size_y);
	while (i < env->piece_size_y)
	{
		get_next_line(0, &gnl);
		env->piece[i] = ft_strdup(gnl);
		i++;
	}
}

void	retrieve_player_data(t_data *env)
{
	int		i;
	int		j;

	i = 0;
	env->playerchar = (env->local_playerchar == 'O') ? 'X' : 'O';
	while (i < env->map_size_y)
	{
		j = 0;
		while (j < env->map_size_x)
		{
			if (env->map[i][j] == env->playerchar)
			{
				env->player_pos_x = j;
				env->player_pos_y = i;
			}
			if (env->map[i][j] == env->local_playerchar)
			{
				env->local_pos_x = j;
				env->local_pos_y = i;
			}
			++j;
		}
		++i;
	}
	env->play_dir = (env->player_pos_y > env->local_pos_y) ? 1 : 0;
}

void	retrieve_data(t_data *env)
{
	char	*gnl;
	int		i;

	i = 0;
	if (!env->map)
		env->map = ft_memalloc(sizeof(char *) * env->map_size_y);
	get_next_line(0, &gnl);
	while (i <= env->map_size_y)
	{
		get_next_line(0, &gnl);
		if (ft_isdigit(gnl[0]))
			env->map[i] = ft_strdup(gnl + 4);
		else
			retrieve_piece(env, gnl);
		++i;
	}
	if (env->player_pos_x == 0 && env->player_pos_y == 0 &&
		env->local_pos_x == 0 && env->local_pos_y == 0)
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
	env->local_playerchar = (ft_atoi(gnl + 10) == 1) ? 'O' : 'X';
	while (42)
	{
		get_next_line(0, &gnl);
		env->map_size_y = ft_atoi(&gnl[8]);
		env->map_size_x = ft_atoi(&gnl[11]);
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
