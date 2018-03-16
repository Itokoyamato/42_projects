/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rgba.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 15:28:15 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/17 17:13:21 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			rgbatohex(t_rgba c)
{
	int		hex;

	hex = 0;
	hex += (int)(c.r) << 16;
	hex += (int)(c.g) << 8;
	hex += (int)(c.b);
	return (hex);
}

t_rgba		hextorgba(int hex)
{
	t_rgba c;

	c.r = ((hex >> 16) & 0xFF);
	c.g = ((hex >> 8) & 0xFF);
	c.b = ((hex) & 0xFF);
	c.a = 255;
	return (c);
}

t_rgba		rgba(int r, int g, int b, int a)
{
	t_rgba c;

	c.r = r;
	c.g = g;
	c.b = b;
	c.a = a;
	return (c);
}

t_rgba		blend(t_rgba fg, t_rgba bg)
{
	t_rgba		result;
	int			alpha;
	int			inv_alpha;

	alpha = fg.a + 1;
	inv_alpha = 256 - fg.a;
	result.r = (int)(alpha * fg.r + inv_alpha * bg.r) >> 8;
	result.g = (int)(alpha * fg.g + inv_alpha * bg.g) >> 8;
	result.b = (int)(alpha * fg.b + inv_alpha * bg.b) >> 8;
	result.a = 255;
	return (result);
}
