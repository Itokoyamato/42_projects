/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_settings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:30:43 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/18 16:13:08 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

t_point	point(float x, float y)
{
	t_point		point;

	point.x = x;
	point.y = y;
	return (point);
}

void	draw_rec(t_img *img, t_point pos, t_point size, t_rgba color)
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

void	draw_color_picker(t_mlx *mlx, t_img *img, t_point pos)
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
			if (p.y >= 30 && p.y <= 50 && p.x >= 70 && p.x <= 170)
				set_image_pixel(img, pos.x + p.x, pos.y + p.y, rgbatohex(
					hsvtorgba(s->p_hue, (p.x - 70) / 100, s->p_val)));
			if (p.y >= 30 && p.y <= 50 && p.x >= 190 && p.x <= 290)
				set_image_pixel(img, pos.x + p.x, pos.y + p.y, rgbatohex(
					hsvtorgba(s->p_hue, s->p_sat, (p.x - 190) / 100)));
		}
	}
	mlx->settings->p_pos = pos;
}
