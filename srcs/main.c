/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 11:02:51 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/17 17:23:55 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

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
		return (err("Usage: /mlx map_file"));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || !parse_map(fd, &map))
		return (err("Error: invalid file"));
	mlx = init_fdf("FdF", map);
	render_fdf(mlx);
	mlx_key_hook(mlx->win, hook_keydown, mlx);
	mlx_hook(mlx->win, 4, 0, hook_mousedown, mlx);
	mlx_hook(mlx->win, 5, 0, hook_mouseup, mlx);
	mlx_hook(mlx->win, 6, 0, hook_mousemove, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
