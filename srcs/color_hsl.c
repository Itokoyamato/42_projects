/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_hsl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 16:45:40 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/13 17:06:29 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static t_rgba	hsvtorgb_util3(t_rgba c, int hi, t_pqt hex)
{
	if (hi == 3)
	{
		c.r = hex.p * 255;
		c.g = hex.q * 255;
		c.b = hex.v * 255;
		return (c);
	}
	if (hi == 4)
	{
		c.r = hex.t * 255;
		c.g = hex.p * 255;
		c.b = hex.v * 255;
		return (c);
	}
	if (hi == 5)
	{
		c.r = hex.v * 255;
		c.g = hex.p * 255;
		c.b = hex.q * 255;
		return (c);
	}
	return (c);
}

static t_rgba	hsvtorgb_util2(t_rgba c, int hi, t_pqt hex)
{
	if (hi == 0)
	{
		c.r = hex.v * 255;
		c.g = hex.t * 255;
		c.b = hex.p * 255;
		return (c);
	}
	if (hi == 1)
	{
		c.r = hex.q * 255;
		c.g = hex.v * 255;
		c.b = hex.p * 255;
		return (c);
	}
	if (hi == 2)
	{
		c.r = hex.p * 255;
		c.g = hex.v * 255;
		c.b = hex.t * 255;
		return (c);
	}
	return (c);
}

static t_rgba	hsvtorgb_util1(t_rgba c, float h, float s, float v)
{
	float	tmp;
	int		hi;
	t_pqt	hex;

	tmp = h / 60.0;
	hi = floor(tmp);
	hex.p = v * (1 - s);
	hex.q = v * (1 - (tmp - hi) * s);
	hex.t = v * (1 - (1 - (tmp - hi)) * s);
	hex.v = v;
	if (hi <= 2)
		return (hsvtorgb_util2(c, hi, hex));
	if (hi >= 3)
		return (hsvtorgb_util3(c, hi, hex));
	return (c);
}

t_rgba			hsvtorgba(float h, float s, float v)
{
	t_rgba	c;

	c.r = 0;
	c.g = 0;
	c.b = 0;
	c.a = 255;
	if (h < 0)
		h = 0;
	if (h > 359)
		h = 359;
	return (hsvtorgb_util1(c, h, s, v));
}
