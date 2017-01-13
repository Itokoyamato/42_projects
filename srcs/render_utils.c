/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:54:03 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/13 17:06:29 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_vector	calc_vec_rotation(t_vector p, t_cam *r)
{
	t_vector	v;
	double		x;
	double		y;
	double		z;

	x = p.x;
	z = p.z;
	v.x = cos(r->y) * x + sin(r->y) * z;
	v.z = -sin(r->y) * x + cos(r->y) * z;
	y = p.y;
	z = v.z;
	v.y = cos(r->x) * y - sin(r->x) * z;
	v.z = sin(r->x) * y + cos(r->x) * z;
	v.color = p.color;
	return (v);
}

static int	region(int x, int y)
{
	int c;

	c = 0;
	if (y >= sY)
		c |= 1;
	else if (y < 0)
		c |= 2;
	if (x >= sX)
		c |= 4;
	else if (x < 0)
		c |= 8;
	return (c);
}

static void	clip_xy(t_vector *v, t_vector *p1, t_vector *p2, int rout)
{
	if (rout & 1)
	{
		v->x = p1->x + (p2->x - p1->x) * (sY - p1->y) / (p2->y - p1->y);
		v->y = sY - 1;
	}
	else if (rout & 2)
	{
		v->x = p1->x + (p2->x - p1->x) * -p1->y / (p2->y - p1->y);
		v->y = 0;
	}
	else if (rout & 4)
	{
		v->x = sX - 1;
		v->y = p1->y + (p2->y - p1->y) * (sX - p1->x) / (p2->x - p1->x);
	}
	else
	{
		v->x = 0;
		v->y = p1->y + (p2->y - p1->y) * -p1->x / (p2->x - p1->x);
	}
}

int		clipping(t_vector *p1, t_vector *p2)
{
	t_vector	v;
	int			r1;
	int			r2;
	int			rout;

	r1 = region(p1->x, p1->y);
	r2 = region(p2->x, p2->y);
	while (!(!(r1 | r2) || (r1 & r2)))
	{
		rout = r1 ? r1 : r2;
		clip_xy(&v, p1, p2, rout);
		if (rout == r1)
		{
			p1->x = v.x;
			p1->y = v.y;
			r1 = region(p1->x, p1->y);
		}
		else
		{
			p2->x = v.x;
			p2->y = v.y;
			r2 = region(p2->x, p2->y);
		}
	}
	return (!(r1 | r2));
}

void	render_background(t_mlx *mlx)
{
	int			x;
	int			y;
	int			color;

	y = -1;
	while (++y < sY)
	{
		x = -1;
		while (++x < sX)
		{
			color = clerp(rgbatohex(mlx->settings->color1), rgbatohex(mlx->settings->color2), (double)y/sY);
			image_set_pixel(mlx->img, (int)x, (int)y, color);
		}
	}
}

void	render_settings(t_mlx *mlx)
{
	int		x;
	int		y;
	int		color;

	y = 9;
	while (++y <= 40)
	{
		x = 9;
		while (++x <= 380)
		{
			color = rgbatohex(blend(rgba(0, 0, 0, 50), hextorgba(image_get_pixel(mlx->img, x, y))));
			if (x >= 15 && x <= 375 && y >= 15 && y <= 35)
				color = rgbatohex(hsvtorgba(x-15, 1, 1));
			image_set_pixel(mlx->img, (int)x, (int)y, color);
		}
	}
}
