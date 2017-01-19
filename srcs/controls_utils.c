/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:01:36 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/19 18:04:13 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	handle_color_select2(t_mlx *mlx, t_settings *s, t_point m_pos, int tmp)
{
	if (m_pos.x >= s->c5_pos.x && m_pos.x <= s->c5_pos.x + 80 &&
		m_pos.y >= s->c5_pos.y && m_pos.y <= s->c5_pos.y + 20)
		s->selected = 6;
	else if (m_pos.x >= s->c6_pos.x && m_pos.x <= s->c6_pos.x + 80 &&
		m_pos.y >= s->c6_pos.y && m_pos.y <= s->c6_pos.y + 20)
		s->selected = 7;
	if (tmp != s->selected)
		render_fdf(mlx);
}

void	handle_color_select(t_mlx *mlx, t_point m_pos)
{
	t_settings		*s;
	int				tmp;

	s = mlx->settings;
	tmp = s->selected;
	if (m_pos.x >= s->bg_c1_pos.x && m_pos.x <= s->bg_c1_pos.x + 80 &&
		m_pos.y >= s->bg_c1_pos.y && m_pos.y <= s->bg_c1_pos.y + 20)
		s->selected = 0;
	else if (m_pos.x >= s->bg_c2_pos.x && m_pos.x <= s->bg_c2_pos.x + 80 &&
		m_pos.y >= s->bg_c2_pos.y && m_pos.y <= s->bg_c2_pos.y + 20)
		s->selected = 1;
	else if (m_pos.x >= s->c1_pos.x && m_pos.x <= s->c1_pos.x + 80 &&
		m_pos.y >= s->c1_pos.y && m_pos.y <= s->c1_pos.y + 20)
		s->selected = 2;
	else if (m_pos.x >= s->c2_pos.x && m_pos.x <= s->c2_pos.x + 80 &&
		m_pos.y >= s->c2_pos.y && m_pos.y <= s->c2_pos.y + 20)
		s->selected = 3;
	else if (m_pos.x >= s->c3_pos.x && m_pos.x <= s->c3_pos.x + 80 &&
		m_pos.y >= s->c3_pos.y && m_pos.y <= s->c3_pos.y + 20)
		s->selected = 4;
	else if (m_pos.x >= s->c4_pos.x && m_pos.x <= s->c4_pos.x + 80 &&
		m_pos.y >= s->c4_pos.y && m_pos.y <= s->c4_pos.y + 20)
		s->selected = 5;
	handle_color_select2(mlx, s, m_pos, tmp);
}

int		handle_settings(t_mlx *mlx, t_point m_pos)
{
	t_point		cp;
	int			render;

	if (!mlx->settings->display)
		return (0);
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
		update_color(mlx);
	return (0);
}

void	change_depth(t_mlx *mlx, int i)
{
	mlx->settings->depth_multiplier += i;
	if (mlx->settings->depth_multiplier < 1)
		mlx->settings->depth_multiplier = 1;
	if (mlx->settings->depth_multiplier > 50)
		mlx->settings->depth_multiplier = 50;
}

void	toggle_setting(t_mlx *mlx, int setting)
{
	if (setting == 0)
		mlx->settings->tips = !mlx->settings->tips;
	else if (setting == 1)
		mlx->settings->advanced = !mlx->settings->advanced;
	else if (setting == 2)
		if (mlx->settings->advanced)
			mlx->settings->display = !mlx->settings->display;
	render_fdf(mlx);
}
