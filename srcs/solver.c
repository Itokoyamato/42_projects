/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:25:07 by llaporte          #+#    #+#             */
/*   Updated: 2018/01/31 16:05:54 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		already_been_here(t_room *arianne, t_room *current)
{
	while (arianne)
	{
		if (arianne == current)
			return (1);
		arianne = arianne->next;
	}
	return (0);
}

void	add_to_arianne(t_room *arianne, t_room *current)
{
	while (arianne->next)
		arianne = arianne->next;
	arianne->next = current;
}

int		*runner(t_room *current, t_lemin *lem, t_room *arianne)
{
	int		i;
	int		size_paths[current->nb_tunnels + 1];
	t_room	*tunnel;

	i = 0;
	tunnel = current->tunnels;
	while (tunnel)
	{
		if (!already_been_here(arianne, current))
		{
			add_to_arianne(arianne, current);
			size_paths[i] = 1 + runner(tunnel, lem, current);
		}
		else
			size_paths[i] = 0;
		tunnel = tunnel->next;
	}
}

char	*shortest_direction (t_room *current, t_lemin *lem)
{
	int		i;
	int		size_paths[current->nb_tunnels + 1];
	t_room	*tunnel;

	i = 0;
	tunnel = current->tunnels;
	while (tunnel)
	{
		size_paths[i] = runner(tunnel, lem, current);
		tunnel = tunnel->next;
	}
}

void	solver(t_lemin *lem)
{
	init_ants(lem);
}
