/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:23:41 by dthuilli          #+#    #+#             */
/*   Updated: 2017/06/07 10:48:47 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		viewport_fit(t_viewport *v)
{
	double w;
	double h;

	w = v->xmax - v->xmin;
	h = v->ymax - v->ymin;
	if (w / h >= (float)SX / SY)
	{
		v->ymin = -(w * SY / SX / 2);
		v->ymax = w * SY / SX / 2;
	}
	else
	{
		v->xmin = -(h * SX / SY / 2);
		v->xmax = (h * SX / SY / 2);
	}
}

void		reset_viewport(t_mlx *mlx)
{
	mlx->viewport.offx = 0;
	mlx->viewport.offy = 0;
	mlx->fractal->viewport(&mlx->viewport);
	viewport_fit(&mlx->viewport);
	mlx->viewport.max = 32;
	mlx->viewport.zoom = 1.0f;
}

t_complex	screen_to_complex(int x, int y, t_viewport *v)
{
	t_complex	p;

	p.r = (((double)x / SX) * (v->xmax - v->xmin)) * v->zoom
		+ v->xmin + v->offx;
	p.i = (((double)y / SY) * (v->ymax - v->ymin)) * v->zoom
		+ v->ymin + v->offy;
	return (p);
}

t_point		point(float x, float y)
{
	t_point		point;

	point.x = x;
	point.y = y;
	return (point);
}
