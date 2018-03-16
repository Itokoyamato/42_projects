/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:22:12 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/20 16:31:37 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		hook_keyup(int key, t_mlx *mlx)
{
	mlx->controls->isdown[key] = 0;
	return (0);
}

int		hook_keydown(int key, t_mlx *mlx)
{
	(void)mlx;
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 18)
		toggle_setting(mlx, 0);
	if (key == 19)
		toggle_setting(mlx, 1);
	if (key == 20)
		toggle_setting(mlx, 2);
	if (key == 21)
		change_depth(mlx, 1);
	if (key == 23)
		change_depth(mlx, -1);
	mlx->controls->isdown[key] = 1;
	render_fdf(mlx);
	return (0);
}

int		hook_mousedown(int button, int x, int y, t_mlx *mlx)
{
	t_point		cpicker;

	cpicker = mlx->settings->p_pos;
	if (y < 0)
		return (0);
	if (handle_settings(mlx, point(x, y)))
		render_fdf(mlx);
	handle_color_select(mlx, point(x, y));
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
	int		sy;
	int		toggle;

	sy = mlx->sy;
	toggle = (mlx->settings->advanced && mlx->settings->display);
	mlx->controls->m_lastx = mlx->controls->m_x;
	mlx->controls->m_lasty = mlx->controls->m_y;
	mlx->controls->m_x = x;
	mlx->controls->m_y = y;
	if (mlx->controls->isdown[274])
	{
		if (x >= 10 && x <= 460 && y >= sy - 230 && y <= sy - 150 && toggle)
			handle_settings(mlx, point(x, y));
		else if (x >= 10 && x <= 510 && y >= sy - 140 && y <= sy - 10
			&& toggle)
			;
		else if (mlx->controls->isdown[274] && mlx->controls->isdown[256])
			update_rotation(mlx, x, y);
		else if (mlx->controls->isdown[274] && mlx->controls->isdown[259])
			update_zoom(mlx, y);
		else
			update_position(mlx, x, y);
		render_fdf(mlx);
	}
	return (0);
}
