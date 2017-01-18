/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:16:33 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/18 16:10:39 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	update_color(t_mlx *mlx)
{
	mlx->settings->bg_c1 = hsvtorgba(mlx->settings->p_hue,
		mlx->settings->p_sat, mlx->settings->p_val);
	render_background(mlx);
}

void	update_rotation(t_mlx *mlx, int x, int y)
{
	mlx->cam->x += (mlx->controls->m_lasty - y) / 200.0f;
	mlx->cam->y -= (mlx->controls->m_lastx - x) / 200.0f;
}

void	update_zoom(t_mlx *mlx, int y)
{
	mlx->cam->scale += (mlx->controls->m_lasty - y) / 10.0f + 0.5f;
	if (mlx->cam->scale < 1)
		mlx->cam->scale = 1;
}

void	update_position(t_mlx *mlx, int x, int y)
{
	mlx->cam->offsetx += (x - mlx->controls->m_lastx);
	mlx->cam->offsety += (y - mlx->controls->m_lasty);
}
