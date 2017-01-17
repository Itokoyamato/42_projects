/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:15:53 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/17 17:32:20 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx		*init_fdf(char *title, t_map *map)
{
	t_mlx	*mlx;

	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	mlx->sX = minsX + map->width * 50;
	mlx->sY = minsY + map->height * 50;
	if (mlx->sX > maxsX)
		mlx->sX = maxsX;
	if (mlx->sY > maxsY)
		mlx->sY = maxsY;
	if ((mlx->mlx = mlx_init()) == NULL ||
		(mlx->win = mlx_new_window(mlx->mlx, mlx->sX, mlx->sY, title)) == NULL
		|| (mlx->cam = ft_memalloc(sizeof(t_cam))) == NULL
		|| (mlx->mouse = ft_memalloc(sizeof(t_mouse))) == NULL
		|| (mlx->settings = ft_memalloc(sizeof(t_settings))) == NULL
		|| (mlx->img = new_image(mlx)) == NULL
		|| (mlx->background = new_image(mlx)) == NULL)
		err("Error: could not initialize FdF");
	mlx->map = map;
	mlx->cam->x = 0;
	mlx->cam->y = 0;
	mlx->cam->scale = 32;
	while (map->width * mlx->cam->scale >= mlx->sX ||
		map->height * mlx->cam->scale >= mlx->sY)
	{
		if (mlx->cam->scale <= 1)
		{
			mlx->cam->scale = 1;
			break ;
		}
		--mlx->cam->scale;
	}
	mlx->cam->offsetx = mlx->sX / 2;
	mlx->cam->offsety = mlx->sY / 2;
	mlx->settings->color1 = rgba(204, 204, 204, 255);
	mlx->settings->color1 = rgba(100, 100, 100, 255);
	render_background(mlx);
	return (mlx);
}

t_mlx		*exit_fdf(t_mlx *mlx)
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
