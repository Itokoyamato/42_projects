/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 19:10:20 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/24 19:10:21 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	int			i;
	char		**map;
	t_map_info	map_info;
	t_map_info	*map_info_p;

	map = 0;
	map_info_p = &map_info;
	i = 1;
	if (argc == 1)
	{
		if ((map = get_map(get_input(), map_info_p)))
			print_result(map, map_info, solve_bsq(map, map_info));
	}
	while (i < argc)
	{
		if ((map = get_map(argv[i], map_info_p)))
			print_result(map, map_info, solve_bsq(map, map_info));
		else
			ft_putstr("map error");
		i++;
	}
	return (0);
}
