/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 12:02:23 by llaporte          #+#    #+#             */
/*   Updated: 2018/02/07 16:06:16 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_ants(t_lemin *lem)
{
	int		i;
	t_ant	*ants;

	i = 1;
	if (!(lem->ants = (t_ant*)ft_memalloc(sizeof(t_ant))))
		err("Can't allocate memory for first ant", lem);
	lem->ants->current_room = lem->start_room;
	lem->ants->id = i;
	ants = lem->ants;
	++i;
	while (i <= lem->ants_nb)
	{
		if (!(ants->next = (t_ant*)ft_memalloc(sizeof(t_ant))))
			err("Can't allocate memory for an ant", lem);
		ants = ants->next;
		ants->current_room = lem->start_room;
		ants->id = i;
		++i;
	}
}

void	move_ant(t_ant *ant, t_room *target_room)
{
	ant->current_room = target_room;
	ft_putchar('L');
	ft_putnbr(ant->id);
	ft_putchar('-');
	ft_putstr(ant->current_room->name);
	ft_putchar(' ');
}
