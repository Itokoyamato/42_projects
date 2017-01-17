/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:16:33 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/17 17:30:20 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		hook_mousedown(int button, int x, int y, t_mlx *mlx)
{
	if (y < 0)
		return (0);
	if (x >= 15 && x <= 375 && y >= 15 && y <= 35)
	{
		mlx->settings->color1 = hsvtorgba(x - 15, 1, 1);
		render_fdf(mlx);
	}
	mlx->mouse->isdown |= 1 << button;
	return (0);
}

int		hook_mouseup(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	mlx->mouse->isdown &= ~(1 << button);
	return (0);
}

int		hook_mousemove(int x, int y, t_mlx *mlx)
{
	mlx->mouse->lastx = mlx->mouse->x;
	mlx->mouse->lasty = mlx->mouse->y;
	mlx->mouse->x = x;
	mlx->mouse->y = y;
	if (mlx->mouse->isdown && x >= 15 && x <= 375 && y >= 15 && y <= 35)
	{
		mlx->settings->color1 = hsvtorgba(x - 15, 1, 1);
		render_background(mlx);
	}
	else if (mlx->mouse->isdown & (1 << 1) && mlx->mouse->isdown & (1 << 2))
	{
		mlx->cam->x += (mlx->mouse->lasty - y) / 200.0f;
		mlx->cam->y -= (mlx->mouse->lastx - x) / 200.0f;
	}
	else if (mlx->mouse->isdown & (1 << 1))
	{
		mlx->cam->offsetx += (x - mlx->mouse->lastx);
		mlx->cam->offsety += (y - mlx->mouse->lasty);
	}
	else if (mlx->mouse->isdown & (1 << 2))
	{
		mlx->cam->scale += (mlx->mouse->lasty - y) / 10.0f + 0.5f;
		if (mlx->cam->scale < 1)
			mlx->cam->scale = 1;
	}
	if (mlx->mouse->isdown)
		render_fdf(mlx);
	return (0);
}

int		hook_keydown(int key, t_mlx *mlx)
{
	(void)mlx;
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 83)
		mlx->cam->scale += 2;
	if (key == 86)
		mlx->cam->scale -= 2;
	if (key == 84)
		mlx->cam->x += 0.1;
	if (key == 87)
		mlx->cam->x -= 0.1;
	if (key == 85)
		mlx->cam->y += 0.1;
	if (key == 88)
		mlx->cam->y -= 0.1;
	if (mlx->cam->scale < 1)
		mlx->cam->scale = 1;
	render_fdf(mlx);
	return (0);
}
