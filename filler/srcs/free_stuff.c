/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 17:15:22 by dthuilli          #+#    #+#             */
/*   Updated: 2017/06/11 17:16:03 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_map(t_data *env)
{
	int		i;

	i = 0;
	if (env->map)
	{
		while (i < env->map_size.y)
		{
			if (env->map && env->map[i])
			{
				free(env->map[i]);
				env->map[i] = NULL;
			}
			++i;
		}
		free(env->map);
		env->map = NULL;
	}
}

void	free_piece(t_data *env)
{
	int		i;

	i = 0;
	if (env->piece)
	{
		while (i < env->piece_size.y)
		{
			if (env->piece && env->piece[i])
			{
				free(env->piece[i]);
				env->piece[i] = NULL;
			}
			++i;
		}
		free(env->piece);
		env->piece = NULL;
	}
}

void	free_stuff(t_data *env)
{
	free_map(env);
	free_piece(env);
}

void	free_gnl(char *gnl)
{
	if (gnl && ft_strlen(gnl) > 0)
	{
		free(gnl);
		gnl = NULL;
	}
}
