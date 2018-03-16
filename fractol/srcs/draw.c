/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:25:31 by dthuilli          #+#    #+#             */
/*   Updated: 2017/06/07 10:48:50 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void		draw_fractal(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while (y < SY)
	{
		x = 0;
		while (x < SX)
		{
			set_image_pixel(mlx->img, x, y,
					get_color(*(mlx->data + y * SX + x), mlx));
			x++;
		}
		y++;
	}
}
