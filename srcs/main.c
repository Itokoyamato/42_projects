/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:02:51 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/20 16:41:51 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>

int		err(char *err)
{
	ft_putendl(err);
	return (1);
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	t_map	*map;
	int		fd;

	if (argc < 2)
		return (err("Usage: /fdf map_file"));
	if ((mlx = ft_memalloc(sizeof(t_mlx))) == NULL)
		return (err("Error: Failed to init mlx"));
	init_settings(mlx);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || !parse_map(fd, mlx, &map))
		return (err("Error: invalid file"));
	init_fdf(mlx, "FdF", map);
	render_fdf(mlx);
	mlx_hook(mlx->win, 2, 0, hook_keydown, mlx);
	mlx_hook(mlx->win, 3, 0, hook_keyup, mlx);
	mlx_hook(mlx->win, 4, 0, hook_mousedown, mlx);
	mlx_hook(mlx->win, 5, 0, hook_mouseup, mlx);
	mlx_hook(mlx->win, 6, 0, hook_mousemove, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
