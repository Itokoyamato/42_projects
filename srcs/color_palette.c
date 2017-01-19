/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_palette.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:29:00 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/19 17:51:01 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			get_palette_color(t_mlx *mlx, double z, t_map *m, double p)
{
	int			c;
	t_settings	*s;

	s = mlx->settings;
	c = rgbatohex(s->c1);
	if (z > (double)m->depth_min && p <= 0.002)
		c = clerp(rgbatohex(s->c1), rgbatohex(s->c2),
			ft_ilerp(p * 1000, 0, 2));
	if (p >= 0.002 && p <= 0.03)
		c = clerp(rgbatohex(s->c2), rgbatohex(s->c3),
			ft_ilerp(p * 1000, 2, 30));
	if (p >= 0.03 && p <= 0.1)
		c = clerp(rgbatohex(s->c3), rgbatohex(s->c4),
			ft_ilerp(p * 1000, 30, 100));
	if (p >= 0.1 && p <= 0.4)
		c = clerp(rgbatohex(s->c4), rgbatohex(s->c5),
			ft_ilerp(p * 1000, 100, 400));
	if (p >= 0.4)
		c = clerp(rgbatohex(s->c5), rgbatohex(s->c6),
			ft_ilerp(p * 1000, 400, 1000));
	return (c);
}

void		set_map_colors(t_mlx *mlx, t_map *m)
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
			cur->color = get_palette_color(mlx, cur->z, m, percent);
		}
	}
}
