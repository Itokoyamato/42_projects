/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 16:47:56 by dthuilli          #+#    #+#             */
/*   Updated: 2018/02/07 16:48:02 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		destroy_rooms(t_room *list)
{
	if (list)
	{
		if (list->next)
			destroy_rooms(list->next);
		destroy_roomlist(list->tunnels);
		list->tunnels_start = NULL;
		free(list->name);
		free(list);
	}
}

void		destroy_ants(t_ant *list)
{
	if (list)
	{
		if (list->next)
			destroy_ants(list->next);
		free(list);
	}
}
