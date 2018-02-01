/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:25:07 by llaporte          #+#    #+#             */
/*   Updated: 2018/02/01 16:20:29 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*shortest_direction (t_room *current, t_lemin *lem)
{
	int		depth;
	t_tunnel	*tunnel;

	depth = 1;
	tunnel = current->tunnels;
	while (tunnel)
	{

	}
	return (NULL);
}

void	solver(t_lemin *lem)
{
	init_ants(lem);
	ft_putstr(shortest_direction(lem->start_room, lem));
}
