/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:29:30 by dthuilli          #+#    #+#             */
/*   Updated: 2018/02/08 13:50:33 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_2d(char **table)
{
	int	i;

	i = -1;
	while (table[++i])
		free(table[i]);
	free(table);
}

void	save_line(t_lemin *lem, char *l)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(l, "\n");
	tmp2 = ft_strdup(lem->input_str);
	if (lem->input_str[0])
		free(lem->input_str);
	lem->input_str = ft_strjoin(tmp2, tmp);
	free(tmp);
	free(tmp2);
}

void	parse_ants(t_lemin *lem, char *l)
{
	char	*tofree;

	if ((lem->ants_nb = ft_atoi(l)) <= 0)
		err("Error: invalid ants count.", lem);
	if ((ft_strcmp(tofree = ft_itoa(lem->ants_nb), l)))
	{
		free(tofree);
		err("Error: invalid ants count. (overflow)", lem);
	}
	free(tofree);
}

void	parse_data(t_lemin *lem)
{
	char	*l;
	int		start_end;

	start_end = 0;
	while (ft_gnl(0, &l) > 0 && ft_strcmp(l, ""))
	{
		save_line(lem, l);
		if (!lem->ants_nb && ft_isstrdigit(l))
			parse_ants(lem, l);
		else if (!ft_strstr(l, "-"))
		{
			if (!parse_rooms(lem, l, &start_end))
			{
				err("Error: Invalid anthill.", lem);
				free(l);
			}
		}
		else if (!parse_tunnels(lem, l))
			break ;
		free(l);
	}
	if (!lem->ants_nb || !lem->start_room || !lem->end_room || !lem->rooms
		|| !lem->rooms->next)
		err("Error: Invalid anthill.", lem);
}
