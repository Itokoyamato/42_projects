/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_bsq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdaniel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 19:45:24 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/24 19:45:25 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		set_values(t_square *bsq, t_square s, t_point p)
{
	bsq->x = p.x;
	bsq->y = p.y;
	bsq->length = s.length;
}

void		test_square(char **map, t_map_info map_info
	, t_square *bsq, t_point p)
{
	t_square	s;
	int			end;

	s.y = 0;
	s.x = -1;
	s.length = 0;
	end = 0;
	while (map[p.y + s.y] != NULL && end == 0)
	{
		++s.length;
		s.y = 0;
		while (s.y < s.length && end == 0)
		{
			while (++s.x < s.length && end == 0)
				if (map[p.y + s.y][p.x + s.x] == '\0'
					|| map[p.y + s.y][p.x + s.x] == map_info.obs)
					end = 1;
			s.x = -1;
			++s.y;
		}
	}
	--s.length;
	if (s.length > bsq->length)
		set_values(bsq, s, p);
}

t_square	find_biggest_square(char **map, t_map_info info)
{
	t_point		pos;
	t_square	bsq;

	bsq.x = 0;
	bsq.y = 0;
	bsq.length = 0;
	pos.y = 0;
	pos.x = 0;
	while (map[pos.y])
	{
		while (map[pos.y][pos.x] != '\0')
		{
			if (map[pos.y][pos.x] != info.obs)
				test_square(map, info, &bsq, pos);
			++pos.x;
		}
		pos.x = 0;
		++pos.y;
	}
	return (bsq);
}

t_square	solve_bsq(char **map, t_map_info map_info)
{
	t_square bsq;

	bsq = find_biggest_square(map, map_info);
	return (bsq);
}
