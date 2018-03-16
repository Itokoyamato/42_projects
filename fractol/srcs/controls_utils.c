/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:39:31 by dthuilli          #+#    #+#             */
/*   Updated: 2017/06/07 10:48:50 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

void		zoom(int x, int y, t_viewport *v, double z)
{
	double w;
	double h;
	double nw;
	double nh;

	w = (v->xmax - v->xmin) * (v->zoom);
	h = (v->ymax - v->ymin) * (v->zoom);
	nw = (v->xmax - v->xmin) * (v->zoom * z);
	nh = (v->ymax - v->ymin) * (v->zoom * z);
	v->zoom *= z;
	v->offx -= ((double)x / SX) * (nw - w);
	v->offy -= ((double)y / SY) * (nh - h);
}

void		handle_color_select(t_mlx *mlx, t_point m_pos)
{
	t_settings		*s;
	int				tmp;

	s = mlx->settings;
	tmp = s->selected;
	if (m_pos.x >= s->c1_pos.x && m_pos.x <= s->c1_pos.x + 80 &&
		m_pos.y >= s->c1_pos.y && m_pos.y <= s->c1_pos.y + 20)
		s->selected = 0;
	else if (m_pos.x >= s->c2_pos.x && m_pos.x <= s->c2_pos.x + 80 &&
		m_pos.y >= s->c2_pos.y && m_pos.y <= s->c2_pos.y + 20)
		s->selected = 1;
	else if (m_pos.x >= s->c3_pos.x && m_pos.x <= s->c3_pos.x + 80 &&
		m_pos.y >= s->c3_pos.y && m_pos.y <= s->c3_pos.y + 20)
		s->selected = 2;
	else if (m_pos.x >= s->c4_pos.x && m_pos.x <= s->c4_pos.x + 80 &&
		m_pos.y >= s->c4_pos.y && m_pos.y <= s->c4_pos.y + 20)
		s->selected = 3;
	else if (m_pos.x >= s->c5_pos.x && m_pos.x <= s->c5_pos.x + 80 &&
		m_pos.y >= s->c5_pos.y && m_pos.y <= s->c5_pos.y + 20)
		s->selected = 4;
}

int			handle_settings(t_mlx *mlx, t_point m_pos)
{
	t_point		cp;
	int			dorender;

	if (!mlx->settings->display)
		return (0);
	cp = mlx->settings->p_pos;
	dorender = 0;
	if (m_pos.x >= cp.x && m_pos.x <= cp.x + 360 &&
		m_pos.y >= cp.y && m_pos.y <= cp.y + 20 && (dorender = 1))
		mlx->settings->p_hue = m_pos.x - cp.x;
	else if (m_pos.x >= cp.x + 70 && m_pos.x <= cp.x + 170 &&
		m_pos.y >= cp.y + 30 && m_pos.y <= cp.y + 50 && (dorender = 1))
		mlx->settings->p_sat = (m_pos.x - cp.x - 70) / 100;
	else if (m_pos.x >= cp.x + 190 && m_pos.x <= cp.x + 290 &&
		m_pos.y >= cp.y + 30 && m_pos.y <= cp.y + 50 && (dorender = 1))
		mlx->settings->p_val = (m_pos.x - cp.x - 190) / 100;
	if (dorender)
		update_color(mlx);
	return (0);
}

void		toggle_setting(t_mlx *mlx, int setting)
{
	if (setting == 0)
		mlx->settings->tips = !mlx->settings->tips;
	else if (setting == 1)
		mlx->settings->display = !mlx->settings->display;
	else if (setting == 2)
		mlx->settings->mouselock = !mlx->settings->mouselock;
	else if (setting == 3)
		mlx->settings->smooth = !mlx->settings->smooth;
	render_fractol(mlx);
}
