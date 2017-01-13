/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:02:51 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/13 17:06:28 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int		error(char *err)
{
	ft_putendl(err);
	return (1);
}

int		hook_mousedown(int button, int x, int y, t_mlx *mlx)
{
	if (y < 0)
		return (0);
	if (x >= 15 && x <= 375 && y >= 15 && y <= 35)
	{
		mlx->settings->color1 = hsvtorgba(x-15, 1, 1);
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
		mlx->settings->color1 = hsvtorgba(x-15, 1, 1);
	else if (mlx->mouse->isdown & (1 << 1) && mlx->mouse->isdown & (1 << 2))
	{
		mlx->cam->offsetx += (x - mlx->mouse->lastx);
		mlx->cam->offsety += (y - mlx->mouse->lasty);
	}
	else if (mlx->mouse->isdown & (1 << 1))
	{
		mlx->cam->x += (mlx->mouse->lasty - y) / 200.0f;
		mlx->cam->y -= (mlx->mouse->lastx - x) / 200.0f;
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
	return (0);
}

t_mlx		*stop_mlx(t_mlx *mlx)
{
	if (mlx->win != NULL)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->cam != NULL)
		ft_memdel((void **)&mlx->cam);
	if (mlx->mouse != NULL)
		ft_memdel((void **)&mlx->mouse);
	if (mlx->img != NULL)
		del_image(mlx, mlx->img);
	ft_memdel((void **)&mlx);
	return (NULL);
}

t_mlx		*init_fdf(char *title)
{
	t_mlx	*mlx;

	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	if ((mlx->mlx = mlx_init()) == NULL ||
		(mlx->win = mlx_new_window(mlx->mlx, sX, sY, title)) == NULL ||
		(mlx->cam = ft_memalloc(sizeof(t_cam))) == NULL ||
		(mlx->mouse = ft_memalloc(sizeof(t_mouse))) == NULL ||
		(mlx->settings = ft_memalloc(sizeof(t_settings))) == NULL ||
		(mlx->img = new_image(mlx)) == NULL)
		return (stop_mlx(mlx));
	mlx->cam->x = 0.5;
	mlx->cam->y = 0.5;
	mlx->cam->scale = 32;
	mlx->cam->offsetx = sX / 2;
	mlx->cam->offsety = sY / 2;
	mlx->settings->color1 = rgba(204, 204, 204, 255);
	mlx->settings->color1 = rgba(100, 100, 100, 255);
	return (mlx);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_map	*map;
	int		fd;

	if (argc < 2)
		return (error("Usage: /mlx map_file"));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || !parse_map(fd, &map))
		return (error("Error: invalid file"));
	if ((mlx = init_fdf("FdF")) == NULL)
		return (error("Error: mlx init failed"));
	mlx->map = map;
	render_fdf(mlx);
	mlx_key_hook(mlx->win, hook_keydown, mlx);
	mlx_hook(mlx->win, 4, 0, hook_mousedown, mlx);
	mlx_hook(mlx->win, 5, 0, hook_mouseup, mlx);
	mlx_hook(mlx->win, 6, 0, hook_mousemove, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
