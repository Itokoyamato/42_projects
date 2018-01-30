/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:25:07 by llaporte          #+#    #+#             */
/*   Updated: 2018/01/30 17:42:33 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_ants(t_lemin *lem)
{
	int		i;
	t_ant	*ants;

	i = 1;
	if (!(lem->ants = (t_ant*)ft_memalloc(sizeof(t_ant))))
		err("Can't allocate memory for first ant");
	lem->ants->current_room = lem->start_room;
	lem->ants->id = i;
	ants = lem->ants;
	while (i++ <= lem->ants_nb)
	{

		if (!(ants = (t_ant*)ft_memalloc(sizeof(t_ant))))
			err("Can't allocate memory for an ant");
		ants->current_room = lem->start_room;
		ants->id = i;
		ants = ants->next;
	}
	ft_putnbr(lem->ants->id);
	while (ants)
	{
		ft_putchar('\n');
		ft_putnbr(ants->id);
		ants = ants->next;
	}
}

void	solver(t_lemin *lem)
{
	ft_putchar('\n');
	ft_putnbr(lem->ants_nb);
	ft_putchar('\n');
	init_ants(lem);
}
