/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:47:24 by dthuilli          #+#    #+#             */
/*   Updated: 2017/03/13 17:26:49 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "math.h"

t_color		clerp(t_color c1, t_color c2, double p)
{
	t_color c;

	if (c1.value == c2.value)
		return (c1);
	c.rgba.r = (char)ft_lerpi((int)c1.rgba.r, (int)c2.rgba.r, p);
	c.rgba.g = (char)ft_lerpi((int)c1.rgba.g, (int)c2.rgba.g, p);
	c.rgba.b = (char)ft_lerpi((int)c1.rgba.b, (int)c2.rgba.b, p);
	c.rgba.a = (char)0x00;
	return (c);
}

t_color		linear_color(double i, int max, t_rgba *colors)
{
	double		index;
	double		adjust;
	int			c;

	index = i / max;
	c = 5 - 1;
	adjust = fmod(index, 1.0f / c) * c;
	return (clerp((t_color)(colors[(int)(index * c) + 1]),
		(t_color)(colors[(int)(index * c)]),
		(int)(adjust + 1) - adjust));
}

t_color		smooth_color(t_pixel p, int max, t_rgba *colors)
{
	double i;
	double zn;
	double nu;

	zn = log(p.c.r * p.c.r + p.c.i * p.c.i) / 2.0f;
	nu = log(zn / log(2)) / log(2);
	i = p.i + 1 - nu;
	if (i < 0)
		i = 0;
	return (linear_color(i, max, colors));
}

int			get_color(t_pixel p, t_mlx *mlx)
{
	if (p.i >= mlx->viewport.max)
		return (0x000000);
	if (mlx->settings->smooth)
	{
		return (smooth_color(p, mlx->viewport.max,
			mlx->settings->colors).value);
	}
	return (linear_color((double)p.i, mlx->viewport.max,
		mlx->settings->colors).value);
}
