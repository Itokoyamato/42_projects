/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:47:04 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/17 17:06:58 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			draw_point(t_mlx *mlx, t_line *l, t_vector *p1, t_vector *p2)
{
	double	percent;

	if (p1->x < 0 || p1->x >= mlx->sX || p1->y < 0 || p1->y >= mlx->sY
		|| p2->x < 0 || p2->x >= mlx->sX || p2->y < 0 || p2->y >= mlx->sY)
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
