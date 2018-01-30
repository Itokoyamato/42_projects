/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:24:00 by dthuilli          #+#    #+#             */
/*   Updated: 2018/01/30 14:36:01 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		err(char *err)
{
	ft_putendl(err);
	exit(1);
	return (1);
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
	parse_debug(lem);
	return (0);
}
