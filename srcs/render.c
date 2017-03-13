/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:18:16 by dthuilli          #+#    #+#             */
/*   Updated: 2017/03/13 17:51:26 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		render_color_preview(t_mlx *mlx)
{
	t_settings		*s;

	s = mlx->settings;
	draw_rec(mlx->img,
		point(10, sY - 140), point(360, 130), rgba(0, 0, 0, 150));
	draw_rec(mlx->img, point(30, sY - 110), point(80, 20), s->colors[0]);
	mlx->settings->c1_pos = point(30, sY - 110);
	draw_rec(mlx->img, point(30, sY - 50), point(80, 20), s->colors[1]);
	mlx->settings->c2_pos = point(30, sY - 50);
	draw_rec(mlx->img, point(155, sY - 110), point(80, 20), s->colors[2]);
	mlx->settings->c3_pos = point(155, sY - 110);
	draw_rec(mlx->img, point(155, sY - 50), point(80, 20), s->colors[3]);
	mlx->settings->c4_pos = point(155, sY - 50);
	draw_rec(mlx->img, point(275, sY - 110), point(80, 20), s->colors[4]);
	mlx->settings->c5_pos = point(275, sY - 110);
}

void		render_settings(t_mlx *mlx)
{
	draw_rec(mlx->img,
		point(10, sY - 230), point(450, 80), rgba(0, 0, 0, 150));
	draw_color_picker(mlx, mlx->img, point(50, sY - 215));
	render_color_preview(mlx);
}

void		render_tips(t_mlx *mlx)
{
	if (ft_strcmp(mlx->fractal->name, "julia") == 0)
		draw_rec(mlx->img,
			point(10, 10), point(540, 200), rgba(10, 10, 10, 100));
	else
		draw_rec(mlx->img,
			point(10, 30), point(500, 180), rgba(10, 10, 10, 100));
}

void		render_fractol(t_mlx *mlx)
{
	int			x;
	int			y;

	y = 0;
	while (y < sY)
	{
		x = 0;
		while (x < sX)
		{
			*(mlx->data + y * sX + x) =
				mlx->fractal->pixel(x, y, &mlx->viewport, mlx);
			x++;
		}
		y++;
	}
	draw_fractal(mlx);
	if (mlx->settings->display)
		render_settings(mlx);
	if (mlx->settings->tips)
		render_tips(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img->img, 0, 0);
	if (mlx->settings->display)
		render_settings_text(mlx);
	if (mlx->settings->tips)
		render_tips_text(mlx);
}
