/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:23:41 by dthuilli          #+#    #+#             */
/*   Updated: 2017/06/07 11:01:07 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

int		hook_keyup(int key, t_mlx *mlx)
{
	double w;
	double h;

	w = (mlx->viewport.xmax - mlx->viewport.xmin) * mlx->viewport.zoom;
	h = (mlx->viewport.ymax - mlx->viewport.ymin) * mlx->viewport.zoom;
	if (key == 126)
		mlx->viewport.offy -= h * 0.05f;
	if (key == 125)
		mlx->viewport.offy += h * 0.05f;
	if (key == 123)
		mlx->viewport.offx -= w * 0.05f;
	if (key == 124)
		mlx->viewport.offx += w * 0.05f;
	mlx->controls->isdown[key] = 0;
	render_fractol(mlx);
	return (0);
}

int		hook_keydown(int key, t_mlx *mlx)
{
	(void)mlx;
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 7)
		toggle_setting(mlx, 0);
	if (key == 18)
		toggle_setting(mlx, 1);
	if (key == 37)
		toggle_setting(mlx, 2);
	if (key == 1)
		toggle_setting(mlx, 3);
	if (key == 51)
		reset_viewport(mlx);
	if (key == 78)
		if (mlx->viewport.max / 2 >= 2)
			mlx->viewport.max /= 2;
	if (key == 69)
		mlx->viewport.max *= 2;
	mlx->controls->isdown[key] = 1;
	render_fractol(mlx);
	return (0);
}

int		hook_mousedown(int button, int x, int y, t_mlx *mlx)
{
	t_point		cpicker;

	cpicker = mlx->settings->p_pos;
	if (y < 0)
		return (0);
	if (button == 5)
	{
		zoom(x, y, &mlx->viewport, 1 / ZOOM);
		render_fractol(mlx);
	}
	else if (button == 4)
	{
		zoom(x, y, &mlx->viewport, ZOOM);
		render_fractol(mlx);
	}
	if (handle_settings(mlx, point(x, y)))
		render_fractol(mlx);
	handle_color_select(mlx, point(x, y));
	render_fractol(mlx);
	mlx->controls->isdown[273 + button] = 1;
	return (0);
}

int		hook_mouseup(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	mlx->controls->isdown[273 + button] = 0;
	return (0);
}

int		hook_mousemove(int x, int y, t_mlx *mlx)
{
	int		toggle;

	toggle = (mlx->settings->display);
	mlx->controls->m_lastx = mlx->controls->m_x;
	mlx->controls->m_lasty = mlx->controls->m_y;
	mlx->controls->m_x = x;
	mlx->controls->m_y = y;
	if (!mlx->settings->mouselock && !mlx->controls->isdown[256])
		mlx->viewport.mouse = screen_to_complex(x, y, &mlx->viewport);
	if (mlx->controls->isdown[274])
	{
		if (x >= 10 && x <= 460 && y >= SY - 230 && y <= SY - 150 && toggle)
			handle_settings(mlx, point(x, y));
		else if (x >= 10 && x <= 510 && y >= SY - 140 && y <= SY - 10
			&& toggle)
			;
		else if (mlx->controls->isdown[274] && mlx->controls->isdown[256])
			update_zoom(mlx, x, y);
		else if (mlx->settings->mouselock)
			update_position(mlx, x, y);
	}
	render_fractol(mlx);
	return (0);
}
