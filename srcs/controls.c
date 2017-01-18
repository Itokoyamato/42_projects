/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 13:22:12 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/18 16:14:56 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

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
	mlx->controls->m_lastx = mlx->controls->m_x;
	mlx->controls->m_lasty = mlx->controls->m_y;
	mlx->controls->m_x = x;
	mlx->controls->m_y = y;
	if (mlx->controls->isdown[274])
	{
		if (handle_settings(mlx, point(x, y)))
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
