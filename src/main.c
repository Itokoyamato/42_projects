/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:02:38 by dthuilli          #+#    #+#             */
/*   Updated: 2017/03/09 15:48:51 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"
#include "mlx.h"
#include <stdlib.h>

int		err(char *err)
{
	ft_putendl(err);
	exit(1);
	return (1);
}

int		expose(t_mlx *mlx)
{
	render(mlx);
	return (0);
}

t_fractal	*get_fractal(char *str)
{
	int			i;
	static t_fractal fractals[8] = {
		{"mandelbrot", mandelbrot_viewport, mandelbrot_pixel, 0},
		{"julia", julia_viewport, julia_pixel, 1},
		{"burningship", burningship_viewport, burningship_pixel, 0},
		{NULL, NULL, NULL, 0}
	};

	i = 0;
	while (fractals[i].name != NULL)
	{
		if (ft_strcmp(fractals[i].name, str) == 0)
			return (&fractals[i]);
		i++;
	}
	return (&fractals[i]);
}

int		main(int argc, char **argv)
{
	t_mlx		*mlx;
	t_fractal	*fractal;

	if (argc < 2)
		return (err("Usage: /fractol [julia | mandelbrot | burningship"));
	fractal = get_fractal(argv[1]);
	if (fractal->name == NULL)
		return (err("Usage: /fractol [julia | mandelbrot | burningship"));
	if ((mlx = init(fractal)) == NULL)
		return (err("Error: Failed to init mlx"));
	reset_viewport(mlx);
	render(mlx);
	mlx_key_hook(mlx->window, hook_keydown, mlx);
	mlx_expose_hook(mlx->window, expose, mlx);
	mlx_hook(mlx->window, 4, 1L << 2, hook_mousedown, mlx);
	mlx_hook(mlx->window, 5, 1L << 3, hook_mouseup, mlx);
	mlx_hook(mlx->window, 6, 1L << 6, hook_mousemove, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
