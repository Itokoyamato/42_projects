/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_update.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:28:58 by dthuilli          #+#    #+#             */
/*   Updated: 2017/06/07 11:01:31 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	update_color(t_mlx *mlx)
{
	t_rgba	color;

	color = hsvtorgba(mlx->settings->p_hue,
		mlx->settings->p_sat, mlx->settings->p_val);
	if (mlx->settings->selected == 0)
		mlx->settings->colors[0] = color;
	else if (mlx->settings->selected == 1)
		mlx->settings->colors[1] = color;
	else if (mlx->settings->selected == 2)
		mlx->settings->colors[2] = color;
	else if (mlx->settings->selected == 3)
		mlx->settings->colors[3] = color;
	else if (mlx->settings->selected == 4)
		mlx->settings->colors[4] = color;
	render_fractol(mlx);
}

void	update_zoom(t_mlx *mlx, int x, int y)
{
	if (mlx->controls->m_lasty - y < 0)
		zoom(x, y, &mlx->viewport, ZOOM);
	else
		zoom(x, y, &mlx->viewport, 1 / ZOOM);
}

void	update_position(t_mlx *mlx, int x, int y)
{
	mlx->viewport.offx += -((x - mlx->controls->m_lastx) *
												(0.005f * mlx->viewport.zoom));
	mlx->viewport.offy += -((y - mlx->controls->m_lasty) *
												(0.005f * mlx->viewport.zoom));
}
