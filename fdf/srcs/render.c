/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:43:23 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/20 16:37:39 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		render_background(t_mlx *mlx)
{
	int			x;
	int			y;
	int			color;

	y = -1;
	while (++y < mlx->sy)
	{
		x = -1;
		while (++x < mlx->sx)
		{
			color = clerp(rgbatohex(mlx->settings->bg_c1),
				rgbatohex(mlx->settings->bg_c2), (double)y / mlx->sy);
			set_image_pixel(mlx->background, (int)x, (int)y, color);
		}
	}
}

void		render_color_preview(t_mlx *mlx)
{
	t_settings		*s;

	s = mlx->settings;
	draw_rec(mlx->img,
		point(10, mlx->sy - 140), point(500, 130), rgba(0, 0, 0, 150));
	draw_rec(mlx->img, point(30, mlx->sy - 110), point(80, 20), s->bg_c1);
	mlx->settings->bg_c1_pos = point(30, mlx->sy - 110);
	draw_rec(mlx->img, point(30, mlx->sy - 50), point(80, 20), s->bg_c2);
	mlx->settings->bg_c2_pos = point(30, mlx->sy - 50);
	draw_rec(mlx->img,
		point(140, mlx->sy - 130), point(1, 110), rgba(255, 179, 15, 255));
	draw_rec(mlx->img, point(155, mlx->sy - 110), point(80, 20), s->c1);
	mlx->settings->c1_pos = point(155, mlx->sy - 110);
	draw_rec(mlx->img, point(155, mlx->sy - 50), point(80, 20), s->c2);
	mlx->settings->c2_pos = point(155, mlx->sy - 50);
	draw_rec(mlx->img, point(275, mlx->sy - 110), point(80, 20), s->c3);
	mlx->settings->c3_pos = point(275, mlx->sy - 110);
	draw_rec(mlx->img, point(275, mlx->sy - 50), point(80, 20), s->c4);
	mlx->settings->c4_pos = point(275, mlx->sy - 50);
	draw_rec(mlx->img, point(400, mlx->sy - 110), point(80, 20), s->c5);
	mlx->settings->c5_pos = point(400, mlx->sy - 110);
	draw_rec(mlx->img, point(400, mlx->sy - 50), point(80, 20), s->c6);
	mlx->settings->c6_pos = point(400, mlx->sy - 50);
}

void		render_settings(t_mlx *mlx)
{
	draw_rec(mlx->img,
		point(10, mlx->sy - 230), point(450, 80), rgba(0, 0, 0, 150));
	draw_color_picker(mlx, mlx->img, point(50, mlx->sy - 215));
	render_color_preview(mlx);
}

void		render_map(t_mlx *mlx)
{
	int			x;
	int			y;
	t_vector	v;
	t_map		*map;

	map = mlx->map;
	x = -1;
	while (++x < map->width)
	{
		y = -1;
		while (++y < map->height)
		{
			v = math_vec(get_vector(map, x, y), mlx);
			if (x + 1 < map->width)
				draw_line(mlx, v, math_vec(get_vector(map, x + 1, y), mlx));
			if (y + 1 < map->height)
				draw_line(mlx, v, math_vec(get_vector(map, x, y + 1), mlx));
			if (y + 1 < map->height && x + 1 < map->width
				&& mlx->settings->advanced)
				draw_line(mlx, v, math_vec(get_vector(map, x + 1, y + 1), mlx));
		}
	}
}

void		render_fdf(t_mlx *mlx)
{
	clear_image(mlx, mlx->img);
	render_map(mlx);
	if (mlx->settings->tips)
		draw_rec(mlx->img,
			point(10, 10), point(500, 160), rgba(1, 174, 240, 50));
	if (mlx->settings->advanced && mlx->settings->display)
		render_settings(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	if (mlx->settings->advanced && mlx->settings->display)
		render_settings_text(mlx);
	if (mlx->settings->tips)
	{
		mlx_string_put(mlx->mlx, mlx->win, 25, 20, 0xFFFFFFFF,
			"Translate: hold MOUSE_1 + movement");
		mlx_string_put(mlx->mlx, mlx->win, 25, 40, 0xFFFFFFFF,
			"Rotate: hold MOUSE_1 + CTRL + movement");
		mlx_string_put(mlx->mlx, mlx->win, 25, 60, 0xFFFFFFFF,
			"Rotate: hold MOUSE_1 + CMD + vertical movement");
		mlx_string_put(mlx->mlx, mlx->win, 25, 80, 0xFFFFFFFF,
			"Toggle bonus: press '2'");
		mlx_string_put(mlx->mlx, mlx->win, 25, 100, 0xFFFFFFFF,
			"Toggle settings: press '3' (w/ bonus enabled)");
		mlx_string_put(mlx->mlx, mlx->win, 25, 140, 0xFFFFFFFF,
			"Press '1' to toggle this window");
	}
}
