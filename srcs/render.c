/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:43:23 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/18 15:39:30 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		render_background(t_mlx *mlx)
{
	int			x;
	int			y;
	int			color;

	y = -1;
	while (++y < mlx->sY)
	{
		x = -1;
		while (++x < mlx->sX)
		{
			color = clerp(rgbatohex(mlx->settings->bg_c1),
				rgbatohex(mlx->settings->bg_c2), (double)y / mlx->sY);
			set_image_pixel(mlx->background, (int)x, (int)y, color);
		}
	}
}

void		render_settings(t_mlx *mlx)
{
	draw_rec(mlx->img, point(20, 20), point(380, 400), rgba(0, 0, 0, 150));
	draw_color_picker(mlx, mlx->img, point(30, 70));
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
			if (y + 1 < map->height && x + 1 < map->width)
				draw_line(mlx, v, math_vec(get_vector(map, x + 1, y + 1), mlx));
			if (x + 1 < map->width && y - 1 >= 0)
				draw_line(mlx, math_vec(get_vector(map, x, y - 1), mlx),
					math_vec(get_vector(map, x + 1, y), mlx));
		}
	}
}

void		render_fdf(t_mlx *mlx)
{
	clear_image(mlx, mlx->img);
	render_map(mlx);
	render_settings(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	mlx_string_put(mlx->mlx, mlx->win, 165, 30, 0xFF01b0f0, "Settings");
}
