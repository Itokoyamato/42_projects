/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:48:17 by dthuilli          #+#    #+#             */
/*   Updated: 2017/03/13 17:22:36 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "fractol.h"

int			init_settings(t_mlx *mlx, t_fractal *f)
{
	if ((mlx->settings = ft_memalloc(sizeof(t_settings))) == NULL)
		return (0);
	mlx->settings->p_hue = (float)0;
	mlx->settings->p_sat = (float)1;
	mlx->settings->p_val = (float)1;
	mlx->settings->colors[0] = rgba(0, 47, 47, 255);
	mlx->settings->colors[1] = rgba(1, 176, 240, 255);
	mlx->settings->colors[2] = rgba(119, 218, 255, 255);
	mlx->settings->colors[3] = rgba(204, 241, 255, 255);
	mlx->settings->colors[4] = rgba(255, 0, 0, 255);
	mlx->settings->selected = 0;
	mlx->settings->display = 0;
	mlx->settings->tips = 1;
	mlx->settings->mouselock = 1 - f->mouse;
	mlx->settings->smooth = 1;
	return (1);
}

t_mlx		*mlxdel(t_mlx *mlx)
{
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->img != NULL)
		del_image(mlx, mlx->img);
	ft_memdel((void **)&mlx);
	return (NULL);
}

t_mlx		*init(t_fractal *f)
{
	t_mlx	*mlx;
	char	*title;

	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		return (NULL);
	title = ft_strjoin("Fract'ol - ", f->name);
	if ((mlx->mlx = mlx_init()) == NULL
		|| (mlx->window = mlx_new_window(mlx->mlx, sX, sY, title)) == NULL
		|| (mlx->img = new_image(mlx)) == NULL
		|| (mlx->controls = ft_memalloc(sizeof(t_controls))) == NULL
		|| (mlx->data = ft_memalloc(sizeof(t_pixel) * sX * sY)) == NULL)
		return (mlxdel(mlx));
	mlx->mouse.isdown = 0;
	mlx->fractal = f;
	init_settings(mlx, f);
	return (mlx);
}
