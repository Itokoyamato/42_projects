/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:54:03 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/17 16:49:59 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	region(t_mlx *mlx, int x, int y)
{
	int c;

	c = 0;
	if (y >= mlx->sY)
		c |= 1;
	else if (y < 0)
		c |= 2;
	if (x >= mlx->sX)
		c |= 4;
	else if (x < 0)
		c |= 8;
	return (c);
}

static void	clip_xy(t_mlx *mlx, t_vector *v, t_vector *p1, t_vector *p2, int rout)
{
	if (rout & 1)
	{
		v->x = p1->x + (p2->x - p1->x) * (mlx->sY - p1->y) / (p2->y - p1->y);
		v->y = mlx->sY - 1;
	}
	else if (rout & 2)
	{
		v->x = p1->x + (p2->x - p1->x) * -p1->y / (p2->y - p1->y);
		v->y = 0;
	}
	else if (rout & 4)
	{
		v->x = mlx->sX - 1;
		v->y = p1->y + (p2->y - p1->y) * (mlx->sX - p1->x) / (p2->x - p1->x);
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
		clip_xy(mlx, &v, p1, p2, rout);
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
