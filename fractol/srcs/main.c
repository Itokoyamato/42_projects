/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:02:38 by dthuilli          #+#    #+#             */
/*   Updated: 2017/03/13 18:06:38 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

int		err(char *err)
{
	ft_putendl(err);
	exit(1);
	return (1);
}

int		expose(t_mlx *mlx)
{
	render_fractol(mlx);
	return (0);
}

int		main(int argc, char **argv)
{
	t_mlx		*mlx;
	t_fractal	*fractal;

	if (argc < 2)
		return (err("Usage: /fractol [ julia | mandelbrot | burningship ]"));
	fractal = get_fractal(argv[1]);
	if (fractal->name == NULL)
		return (err("Usage: /fractol [ julia | mandelbrot | burningship ]"));
	if ((mlx = init(fractal)) == NULL)
		return (err("Error: Failed to init mlx"));
	reset_viewport(mlx);
	render_fractol(mlx);
	mlx_expose_hook(mlx->window, expose, mlx);
	mlx_hook(mlx->window, 2, 0, hook_keydown, mlx);
	mlx_hook(mlx->window, 3, 0, hook_keyup, mlx);
	mlx_hook(mlx->window, 4, 0, hook_mousedown, mlx);
	mlx_hook(mlx->window, 5, 0, hook_mouseup, mlx);
	mlx_hook(mlx->window, 6, 0, hook_mousemove, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
