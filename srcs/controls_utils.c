/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:39:31 by dthuilli          #+#    #+#             */
/*   Updated: 2017/03/09 15:49:25 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"
#include <stdlib.h>

int		handle_draw(int key, t_mlx *mlx)
{
	int		doot;

	doot = 0;
	if (key >= K_DIGIT_1 && key <= K_DIGIT_1 + 3)
		mlx->palette = &get_palettes()[key - K_DIGIT_1];
	else if (key == K_NUM_ENTER)
		mlx->smooth = 1 - mlx->smooth;
	else
		doot = 1;
	if (!doot)
		draw(mlx);
	return (doot);
}

void	set_render_position(int key, t_mlx *mlx)
{
	double w;
	double h;

	w = (mlx->viewport.xmax - mlx->viewport.xmin) * mlx->viewport.zoom;
	h = (mlx->viewport.ymax - mlx->viewport.ymin) * mlx->viewport.zoom;
	if (key == K_UP)
		mlx->viewport.offy -= h * 0.05f;
	if (key == K_DOWN)
		mlx->viewport.offy += h * 0.05f;
	if (key == K_LEFT)
		mlx->viewport.offx -= w * 0.05f;
	if (key == K_RIGHT)
		mlx->viewport.offx += w * 0.05f;
	if (key == K_L)
		mlx->mouselock = 1 - mlx->mouselock;
}

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
	v->offx -= ((double)x / WIN_WIDTH) * (nw - w);
	v->offy -= ((double)y / WIN_HEIGHT) * (nh - h);
}
