/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:01:36 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/18 16:09:31 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		handle_settings(t_mlx *mlx, t_point m_pos)
{
	t_point		cp;
	int			render;

	cp = mlx->settings->p_pos;
	render = 0;
	if (m_pos.x >= cp.x && m_pos.x <= cp.x + 360 &&
		m_pos.y >= cp.y && m_pos.y <= cp.y + 20 && (render = 1))
		mlx->settings->p_hue = m_pos.x - cp.x;
	else if (m_pos.x >= cp.x + 70 && m_pos.x <= cp.x + 170 &&
		m_pos.y >= cp.y + 30 && m_pos.y <= cp.y + 50 && (render = 1))
		mlx->settings->p_sat = (m_pos.x - cp.x - 70) / 100;
	else if (m_pos.x >= cp.x + 190 && m_pos.x <= cp.x + 290 &&
		m_pos.y >= cp.y + 30 && m_pos.y <= cp.y + 50 && (render = 1))
		mlx->settings->p_val = (m_pos.x - cp.x - 190) / 100;
	if (render)
	{
		update_color(mlx);
		return (1);
	}
	return (0);
}
