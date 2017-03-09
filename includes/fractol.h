/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:43:37 by dthuilli          #+#    #+#             */
/*   Updated: 2017/03/09 15:53:03 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
**** Libs
*/
# include "libft.h"
# include "mlx.h"
# include "typedefs.h"

/*
**** Utils
*/
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define ZOOM 1.1f

t_mlx				*mlxdel(t_mlx *mlx);
t_mlx				*init(t_fractal *f);
void				render(t_mlx *mlx);
void				draw(t_mlx *mlx);

int					hook_expose(t_mlx *mlx);
t_img				*del_image(t_mlx *mlx, t_img *img);
t_img				*new_image(t_mlx *mlx);
void				clear_image(t_img *img);
void				set_image_pixel(t_img *image, int x, int y, int color);
t_fractal			*get_fractal(char *str);

int					get_color(t_pixel p, t_mlx *mlx);
t_palette			*get_palettes();

void				zoom(int x, int y, t_viewport *v, double z);
void				viewport_fit(t_viewport *v);
void				reset_viewport(t_mlx *mlx);
t_complex			screen_to_complex(int x, int y, t_viewport *v);

t_pixel				mandelbrot_pixel(int x, int y, t_viewport *v, t_mlx *mlx);
void				mandelbrot_viewport(t_viewport *v);
t_pixel				burningship_pixel(int x, int y, t_viewport *v, t_mlx *mlx);
void				burningship_viewport(t_viewport *v);
t_pixel				julia_pixel(int x, int y, t_viewport *v, t_mlx *mlx);
void				julia_viewport(t_viewport *v);

int					hook_mousedown(int button, int x, int y, t_mlx *mlx);
int					hook_mouseup(int button, int x, int y, t_mlx *mlx);
int					hook_mousemove(int x, int y, t_mlx *mlx);
int					hook_keydown(int key, t_mlx *mlx);
int					handle_draw(int key, t_mlx *mlx);
void				set_render_position(int key, t_mlx *mlx);
#endif