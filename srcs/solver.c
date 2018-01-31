/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:25:07 by llaporte          #+#    #+#             */
/*   Updated: 2018/01/31 15:07:31 by llaporte         ###   ########.fr       */
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

int		*runner(t_room *current, t_lemin *lem, t_room *arianne)
{
	int		shortest_room;
	t_room	*rooms;
	t_room	*arianne_tmp;

	rooms = lem->rooms;
	while (rooms)
	{
		if (already_been_here(arianne, current))
			return (0);
	}
}

char	*shortest_direction (t_lemin *lem)
{

}

void	solver(t_lemin *lem)
{
	init_ants(lem);
}
