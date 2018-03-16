/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:21:14 by dthuilli          #+#    #+#             */
/*   Updated: 2017/06/07 10:48:48 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		render_settings_text(t_mlx *mlx)
{
	int		w;

	w = 0xFFFFFFFF;
	mlx_string_put(mlx->mlx, mlx->window, 25, SY - 215, w, "H:");
	mlx_string_put(mlx->mlx, mlx->window, 75, SY - 185, w, "S:");
	mlx_string_put(mlx->mlx, mlx->window, 235, SY - 185, w, "V:");
	mlx_string_put(mlx->mlx, mlx->window, 30, SY - 135, w, "Color1:");
	mlx_string_put(mlx->mlx, mlx->window, 30, SY - 80, w, "Color2:");
	mlx_string_put(mlx->mlx, mlx->window, 155, SY - 135, w, "Color3:");
	mlx_string_put(mlx->mlx, mlx->window, 155, SY - 80, w, "Color4:");
	mlx_string_put(mlx->mlx, mlx->window, 275, SY - 135, w, "Color5:");
	render_settings_selected(mlx);
}

void		render_tips_text(t_mlx *mlx)
{
	if (ft_strcmp(mlx->fractal->name, "julia") == 0)
	{
		mlx_string_put(mlx->mlx, mlx->window, 25, 20, 0xFFFFFFFF,
			"Lock mouse: press 'L'");
		mlx_string_put(mlx->mlx, mlx->window, 25, 40, 0xFFFFFFFF,
			"Translate: hold MOUSE_1 + movement (w/ mouse locked)");
	}
	else
		mlx_string_put(mlx->mlx, mlx->window, 25, 40, 0xFFFFFFFF,
			"Translate: hold MOUSE_1 + movement");
	mlx_string_put(mlx->mlx, mlx->window, 25, 60, 0xFFFFFFFF,
		"Zoom: hold MOUSE_1 + CTRL + vertical movement");
	mlx_string_put(mlx->mlx, mlx->window, 25, 80, 0xFFFFFFFF,
		"Toggle color smoothing: press 'S'");
	mlx_string_put(mlx->mlx, mlx->window, 25, 100, 0xFFFFFFFF,
		"Increase/Decrease iterations: press '+/-'");
	mlx_string_put(mlx->mlx, mlx->window, 25, 120, 0xFFFFFFFF,
		"Reset View: press 'Backspace'");
	mlx_string_put(mlx->mlx, mlx->window, 25, 140, 0xFFFFFFFF,
		"Toggle settings: press '1'");
	mlx_string_put(mlx->mlx, mlx->window, 25, 180, 0xFFFFFFFF,
		"Press 'X' to toggle this window");
}

void		render_settings_selected(t_mlx *mlx)
{
	t_point		pos;

	if (mlx->settings->selected == 0)
		pos = mlx->settings->c1_pos;
	else if (mlx->settings->selected == 1)
		pos = mlx->settings->c2_pos;
	else if (mlx->settings->selected == 2)
		pos = mlx->settings->c3_pos;
	else if (mlx->settings->selected == 3)
		pos = mlx->settings->c4_pos;
	else if (mlx->settings->selected == 4)
		pos = mlx->settings->c5_pos;
	mlx_string_put(mlx->mlx, mlx->window, pos.x + 36, pos.y + 1, 0xFF0000, "X");
	mlx_string_put(mlx->mlx, mlx->window, pos.x + 34, pos.y + 1, 0xFF0000, "X");
	mlx_string_put(mlx->mlx, mlx->window, pos.x + 34, pos.y - 1, 0xFF0000, "X");
	mlx_string_put(mlx->mlx, mlx->window, pos.x + 36, pos.y - 1, 0xFF0000, "X");
	mlx_string_put(mlx->mlx, mlx->window, pos.x + 35, pos.y, 0xFFFFFFFF, "X");
}
