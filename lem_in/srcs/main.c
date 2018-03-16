/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:24:00 by dthuilli          #+#    #+#             */
/*   Updated: 2018/02/08 13:54:19 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	err(char *err, t_lemin *lem)
{
	destroy_rooms(lem->rooms);
	destroy_ants(lem->ants);
	if (lem->input_str && lem->input_str[0])
		free(lem->input_str);
	free(lem);
	ft_putstr_fd(err, 1);
	exit(1);
}

void	*s_malloc(size_t size)
{
	void	*var;

	if ((var = ft_memalloc(size)) == NULL)
		exit(0);
	return (var);
}

int		main(void)
{
	t_lemin	*lem;

	lem = (t_lemin *)s_malloc(sizeof(t_lemin));
	lem->input_str = "";
	lem->rooms = NULL;
	parse_data(lem);
	init_ants(lem);
	ft_putstr(lem->input_str);
	ft_putchar('\n');
	solver(lem);
	destroy_rooms(lem->rooms);
	destroy_ants(lem->ants);
	free(lem->input_str);
	free(lem);
	return (0);
}
