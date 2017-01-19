/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:15:53 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/19 18:00:13 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			init_settings(t_mlx *mlx)
{
	if ((mlx->settings = ft_memalloc(sizeof(t_settings))) == NULL)
		return (0);
	mlx->settings->p_hue = (float)0;
	mlx->settings->p_sat = (float)1;
	mlx->settings->p_val = (float)1;
	mlx->settings->bg_c1 = rgba(204, 204, 204, 255);
	mlx->settings->bg_c2 = rgba(50, 50, 50, 255);
	mlx->settings->c1 = rgba(0, 48, 127, 255);
	mlx->settings->c2 = rgba(8, 124, 0, 255);
	mlx->settings->c3 = rgba(5, 81, 0, 255);
	mlx->settings->c4 = rgba(96, 61, 0, 255);
	mlx->settings->c5 = rgba(104, 92, 71, 255);
	mlx->settings->c6 = rgba(255, 255, 255, 255);
	mlx->settings->selected = 0;
	mlx->settings->display = 0;
	mlx->settings->advanced = 0;
	mlx->settings->tips = 1;
	mlx->settings->depth_multiplier = 1;
	render_background(mlx);
	return (1);
}

void		init_data(t_mlx *mlx, t_map *map)
{
	mlx->cam->x = 0;
	mlx->cam->y = 0;
	mlx->cam->scale = 32;
	while (map->width * mlx->cam->scale >= mlx->sx ||
		map->height * mlx->cam->scale >= mlx->sy)
	{
		if (mlx->cam->scale <= 1)
		{
			mlx->cam->scale = 1;
			break ;
		}
		--mlx->cam->scale;
	}
	mlx->cam->offsetx = mlx->sx / 2;
	mlx->cam->offsety = mlx->sy / 2;
}

int			init_mlx(t_mlx *mlx, char *title)
{
	if ((mlx->mlx = mlx_init()) == NULL ||
		(mlx->win = mlx_new_window(mlx->mlx, mlx->sx, mlx->sy, title)) == NULL
			|| (mlx->cam = ft_memalloc(sizeof(t_cam))) == NULL
			|| (mlx->controls = ft_memalloc(sizeof(t_controls))) == NULL
			|| (mlx->img = new_image(mlx)) == NULL
			|| (mlx->background = new_image(mlx)) == NULL)
		return (0);
	return (1);
}

t_mlx		*init_fdf(t_mlx *mlx, char *title, t_map *map)
{
	mlx->sx = MIN_SX + map->width * 50;
	mlx->sy = MIN_SY + map->height * 50;
	if (mlx->sx > MAX_SX)
		mlx->sx = MAX_SX;
	if (mlx->sy > MAX_SY)
		mlx->sy = MAX_SY;
	if (!init_mlx(mlx, title))
		err("Error: could not initialize FdF");
	mlx->map = map;
	init_data(mlx, map);
	init_settings(mlx);
	return (mlx);
}

t_mlx		*exit_fdf(t_mlx *mlx)
{
	if (mlx->win != NULL)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->cam != NULL)
		ft_memdel((void **)&mlx->cam);
	if (mlx->controls != NULL)
		ft_memdel((void **)&mlx->controls);
	if (mlx->img != NULL)
		del_image(mlx, mlx->img);
	ft_memdel((void **)&mlx);
	return (NULL);
}
