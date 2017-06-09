/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 17:55:59 by dthuilli          #+#    #+#             */
/*   Updated: 2017/06/09 19:44:56 by dthuilli         ###   ########.fr       */
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
	env->piece_y = ft_atoi(&gnl[6]);
	while (ft_isdigit(gnl[n]))
		n++;
	n++;
	env->piece_x = ft_atoi(&gnl[n]);
	if (!env->piece)
		env->piece = ft_memalloc(sizeof(char *) * env->piece_y);
	while (i < env->piece_y)
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
	while (i < env->mapy)
	{
		j = 0;
		while (j < env->mapx)
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
	env->move = (env->player_pos_y > env->local_pos_y) ? 1 : 0;
}

void	retrieve_data(t_data *env)
{
	char	*gnl;
	int		i;

	i = 0;
	if (!env->map)
		env->map = ft_memalloc(sizeof(char *) * env->mapy);
	get_next_line(0, &gnl);
	while (i <= env->mapy)
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

int		main(void)
{
	char	*gnl;
	t_data	*env;

	if (!(env = ft_memalloc(sizeof(t_data))))
		return (-1);
	get_next_line(0, &gnl);
	env->local_playerchar = (ft_atoi(gnl + 10) == 1) ? 'O' : 'X';
	get_next_line(0, &gnl);
	env->mapy = ft_atoi(&gnl[8]);
	env->mapx = ft_atoi(&gnl[11]);
	while (1)
	{
		ft_putnbr(env->mapy);
		retrieve_data(env);
	}
	return (0);
}