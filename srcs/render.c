/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:43:23 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/13 17:06:28 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	calc_vec(t_vector v, t_mlx *mlx)
{
	v.x -= (double)(mlx->map->width - 1) / 2.0f;
	v.y -= (double)(mlx->map->height - 1) / 2.0f;
	v.z -= (double)(mlx->map->depth_min + mlx->map->depth_max) / 2.0f;
	v = calc_vec_rotation(v, mlx->cam);
	v.x *= mlx->cam->scale;
	v.y *= mlx->cam->scale;
	v.x += mlx->cam->offsetx;
	v.y += mlx->cam->offsety;
	return (v);
}

t_vector	vec_at(t_map *map, int x, int y)
{
	return (*map->vectors[y * map->width + x]);
}

int			draw_point(t_mlx *mlx, t_line *l, t_vector *p1, t_vector *p2)
{
	double	percent;

	if (p1->x < 0 || p1->x >= sX || p1->y < 0 || p1->y >= sY
		|| p2->x < 0 || p2->x >= sX || p2->y < 0 || p2->y >= sY)
		return (1);
	percent = (l->dx > l->dy ?
			ft_ilerp((int)p1->x, (int)l->start.x, (int)l->stop.x)
			: ft_ilerp((int)p1->y, (int)l->start.y, (int)l->stop.y));
	image_set_pixel(mlx->img, (int)p1->x, (int)p1->y, clerp(p1->color,
				p2->color, percent));
	l->err2 = l->err;
	if (l->err2 > -l->dx)
	{
		l->err -= l->dy;
		p1->x += l->sx;
	}
	if (l->err2 < l->dy)
	{
		l->err += l->dx;
		p1->y += l->sy;
	}
	return (0);
}

void		draw_line(t_mlx *mlx, t_vector p1, t_vector p2)
{
	t_line	line;

	p1.x = (int)p1.x;
	p2.x = (int)p2.x;
	p1.y = (int)p1.y;
	p2.y = (int)p2.y;
	line.start = p1;
	line.stop = p2;
	if (!clipping(&p1, &p2))
		return ;
	line.dx = (int)ft_abs((int)p2.x - (int)p1.x);
	line.sx = (int)p1.x < (int)p2.x ? 1 : -1;
	line.dy = (int)ft_abs((int)p2.y - (int)p1.y);
	line.sy = (int)p1.y < (int)p2.y ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	while (((int)p1.x != (int)p2.x || (int)p1.y != (int)p2.y))
		if (draw_point(mlx, &line, &p1, &p2))
			break ;
}

void		render_fdf(t_mlx *mlx)
{
	int			x;
	int			y;
	t_vector	v;
	t_map		*map;

	map = mlx->map;
	clear_image(mlx->img);
	render_background(mlx);
	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			v = calc_vec(vec_at(map, x, y), mlx);
			if (x + 1 < map->width)
				draw_line(mlx, v, calc_vec(vec_at(map, x + 1, y), mlx));
			if (y + 1 < map->height)
				draw_line(mlx, v, calc_vec(vec_at(map, x, y + 1), mlx));
			y++;
		}
		x++;
	}
	render_settings(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
}
