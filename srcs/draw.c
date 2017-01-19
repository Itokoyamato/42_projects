/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:47:04 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/19 17:49:52 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			draw_point(t_mlx *mlx, t_line *l, t_vector *p1, t_vector *p2)
{
	double	percent;

	if (p1->x < 0 || p1->x >= mlx->sx || p1->y < 0 || p1->y >= mlx->sy
		|| p2->x < 0 || p2->x >= mlx->sx || p2->y < 0 || p2->y >= mlx->sy)
		return (1);
	percent = (l->dx > l->dy ?
			ft_ilerp((int)p1->x, (int)l->start.x, (int)l->stop.x)
			: ft_ilerp((int)p1->y, (int)l->start.y, (int)l->stop.y));
	set_image_pixel(mlx->img, (int)p1->x, (int)p1->y, clerp(p1->color,
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

	line.start = p1;
	line.stop = p2;
	p1.sx = mlx->sx;
	p1.sy = mlx->sy;
	if (!is_line_clipping(mlx, &p1, &p2))
		return ;
	line.dx = ft_abs((int)p2.x - (int)p1.x);
	line.sx = (int)p1.x < (int)p2.x ? 1 : -1;
	line.dy = (int)ft_abs((int)p2.y - (int)p1.y);
	line.sy = (int)p1.y < (int)p2.y ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	while (((int)p1.x != (int)p2.x || (int)p1.y != (int)p2.y))
		if (draw_point(mlx, &line, &p1, &p2))
			break ;
}

void		draw_rec(t_img *img, t_point pos, t_point size, t_rgba color)
{
	int		tmpx;
	t_point	p;

	tmpx = ++size.x;
	++size.y;
	while (--size.y > 0 && (size.x = tmpx))
	{
		while (--size.x > 0)
		{
			p.x = (int)pos.x + (int)size.x;
			p.y = (int)pos.y + (int)size.y;
			set_image_pixel(img, p.x, p.y, rgbatohex(blend(color,
				hextorgba(get_image_pixel(img, p.x, p.y)))));
		}
	}
}

void		draw_color_picker(t_mlx *mlx, t_img *img, t_point pos)
{
	t_point		p;
	t_settings	*s;

	p.x = -1;
	p.y = -1;
	s = mlx->settings;
	while (++p.y <= 90)
	{
		p.x = -1;
		while (++p.x <= 360)
		{
			if (p.y <= 20)
				set_image_pixel(img, pos.x + p.x, pos.y + p.y, rgbatohex(
					hsvtorgba(p.x, s->p_sat, s->p_val)));
			if (p.y >= 30 && p.y <= 50 && p.x >= 50 && p.x <= 150)
				set_image_pixel(img, pos.x + p.x, pos.y + p.y, rgbatohex(
					hsvtorgba(s->p_hue, (p.x - 50) / 100, s->p_val)));
			if (p.y >= 30 && p.y <= 50 && p.x >= 210 && p.x <= 310)
				set_image_pixel(img, pos.x + p.x, pos.y + p.y, rgbatohex(
					hsvtorgba(s->p_hue, s->p_sat, (p.x - 210) / 100)));
		}
	}
	mlx->settings->p_pos = pos;
}
