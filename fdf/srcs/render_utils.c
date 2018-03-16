/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:54:03 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/19 17:50:47 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	region(t_mlx *mlx, int x, int y)
{
	int c;

	c = 0;
	if (y >= mlx->sy)
		c |= 1;
	else if (y < 0)
		c |= 2;
	if (x >= mlx->sx)
		c |= 4;
	else if (x < 0)
		c |= 8;
	return (c);
}

static void	do_clip(t_vector *v, t_vector *p1, t_vector *p2, int rout)
{
	if (rout & 1)
	{
		v->x = p1->x + (p2->x - p1->x) * (p1->sy - p1->y) / (p2->y - p1->y);
		v->y = p1->sy - 1;
	}
	else if (rout & 2)
	{
		v->x = p1->x + (p2->x - p1->x) * -p1->y / (p2->y - p1->y);
		v->y = 0;
	}
	else if (rout & 4)
	{
		v->x = p1->sx - 1;
		v->y = p1->y + (p2->y - p1->y) * (p1->sx - p1->x) / (p2->x - p1->x);
	}
	else
	{
		v->x = 0;
		v->y = p1->y + (p2->y - p1->y) * -p1->x / (p2->x - p1->x);
	}
}

int			is_line_clipping(t_mlx *mlx, t_vector *p1, t_vector *p2)
{
	t_vector	v;
	int			r1;
	int			r2;
	int			rout;

	r1 = region(mlx, p1->x, p1->y);
	r2 = region(mlx, p2->x, p2->y);
	while (!(!(r1 | r2) || (r1 & r2)))
	{
		rout = r1 ? r1 : r2;
		do_clip(&v, p1, p2, rout);
		if (rout == r1)
		{
			p1->x = v.x;
			p1->y = v.y;
			r1 = region(mlx, p1->x, p1->y);
		}
		else
		{
			p2->x = v.x;
			p2->y = v.y;
			r2 = region(mlx, p2->x, p2->y);
		}
	}
	return (!(r1 | r2));
}

void		render_settings_selected(t_mlx *mlx)
{
	t_point		pos;

	if (mlx->settings->selected == 0)
		pos = mlx->settings->bg_c1_pos;
	else if (mlx->settings->selected == 1)
		pos = mlx->settings->bg_c2_pos;
	else if (mlx->settings->selected == 2)
		pos = mlx->settings->c1_pos;
	else if (mlx->settings->selected == 3)
		pos = mlx->settings->c2_pos;
	else if (mlx->settings->selected == 4)
		pos = mlx->settings->c3_pos;
	else if (mlx->settings->selected == 5)
		pos = mlx->settings->c4_pos;
	else if (mlx->settings->selected == 6)
		pos = mlx->settings->c5_pos;
	else if (mlx->settings->selected == 7)
		pos = mlx->settings->c6_pos;
	mlx_string_put(mlx->mlx, mlx->win, pos.x + 36, pos.y + 1, 0xFF000000, "X");
	mlx_string_put(mlx->mlx, mlx->win, pos.x + 34, pos.y + 1, 0xFF000000, "X");
	mlx_string_put(mlx->mlx, mlx->win, pos.x + 34, pos.y - 1, 0xFF000000, "X");
	mlx_string_put(mlx->mlx, mlx->win, pos.x + 36, pos.y - 1, 0xFF000000, "X");
	mlx_string_put(mlx->mlx, mlx->win, pos.x + 35, pos.y, 0xFFFFFFFF, "X");
}

void		render_settings_text(t_mlx *mlx)
{
	int		w;

	w = 0xFFFFFFFF;
	mlx_string_put(mlx->mlx, mlx->win, 25, mlx->sy - 215, w, "H:");
	mlx_string_put(mlx->mlx, mlx->win, 75, mlx->sy - 185, w, "S:");
	mlx_string_put(mlx->mlx, mlx->win, 235, mlx->sy - 185, w, "V:");
	mlx_string_put(mlx->mlx, mlx->win, 30, mlx->sy - 135, w, "BG Color1:");
	mlx_string_put(mlx->mlx, mlx->win, 30, mlx->sy - 80, w, "BG Color2:");
	mlx_string_put(mlx->mlx, mlx->win, 155, mlx->sy - 135, w, "FdF Color1:");
	mlx_string_put(mlx->mlx, mlx->win, 155, mlx->sy - 80, w, "FdF Color2:");
	mlx_string_put(mlx->mlx, mlx->win, 275, mlx->sy - 135, w, "FdF Color3:");
	mlx_string_put(mlx->mlx, mlx->win, 275, mlx->sy - 80, w, "FdF Color4:");
	mlx_string_put(mlx->mlx, mlx->win, 400, mlx->sy - 135, w, "FdF Color5:");
	mlx_string_put(mlx->mlx, mlx->win, 400, mlx->sy - 80, w, "FdF Color6:");
	render_settings_selected(mlx);
}
