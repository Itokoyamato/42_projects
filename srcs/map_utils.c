/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:33:34 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/17 17:01:29 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <limits.h>

int			clerp(int c1, int c2, double p)
{
	int r;
	int g;
	int b;

	if (c1 == c2)
		return (c1);
	r = ft_lerpi((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
	g = ft_lerpi((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
	b = ft_lerpi(c1 & 0xFF, c2 & 0xFF, p);
	return (r << 16 | g << 8 | b);
}

void		get_map_minmax_depth(t_map *m)
{
	int			min;
	int			max;
	t_vector	v;
	t_vector	cur;

	min = INT_MAX;
	max = INT_MIN;
	v.y = 0;
	while (v.y < m->height)
	{
		v.x = 0;
		while (v.x < m->width)
		{
			cur = *m->vectors[(int)v.y * m->width + (int)v.x];
			if (cur.z < min)
				min = cur.z;
			if (cur.z > max)
				max = cur.z;
			v.x++;
		}
		v.y++;
	}
	m->depth_min = min;
	m->depth_max = max;
}

int			get_palette_color(double z, t_map *m, double percent)
{
	int		c;

	c = 0x0000307f;
	if (z > (double)m->depth_min && percent <= 0.002)
		c = clerp(0x0000307f, 0x00087c00, ft_ilerp(percent * 1000, 0, 2));
	if (percent >= 0.002 && percent <= 0.03)
		c = clerp(0x00087c00, 0x00055100, ft_ilerp(percent * 1000, 2, 30));
	if (percent >= 0.03 && percent <= 0.1)
		c = clerp(0x00055100, 0x00603d00, ft_ilerp(percent * 1000, 30, 100));
	if (percent >= 0.1 && percent <= 0.4)
		c = clerp(0x00603d00, 0x00685c47, ft_ilerp(percent * 1000, 100, 400));
	if (percent >= 0.4)
		c = clerp(0x00685c47, 0x00ffffff, ft_ilerp(percent * 1000, 400, 1000));
	return (c);
}

void		set_map_colors(t_map *m)
{
	t_vector	v;
	t_vector	*cur;
	double		percent;

	v.y = -1;
	while (++v.y < m->height)
	{
		v.x = -1;
		while (++v.x < m->width)
		{
			cur = m->vectors[(int)v.y * m->width + (int)v.x];
			percent = cur->z / (double)m->depth_max;
			cur->color = get_palette_color(cur->z, m, percent);
		}
	}
}
