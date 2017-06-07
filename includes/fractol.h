/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:43:37 by dthuilli          #+#    #+#             */
/*   Updated: 2017/06/07 11:01:48 by dthuilli         ###   ########.fr       */
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
# define SX 1280
# define SY 720
# define ZOOM 1.3f

t_mlx			*mlxdel(t_mlx *mlx);
t_mlx			*init(t_fractal *f);
void			render_fractol(t_mlx *mlx);

/*
**** Colors
*/
t_rgba			blend(t_rgba fg, t_rgba bg);
t_rgba			hsvtorgba(float h, float s, float v);
t_rgba			rgba(int r, int g, int b, int a);
t_rgba			hextorgba(int hex);
int				rgbatohex(t_rgba c);

int				hook_expose(t_mlx *mlx);
t_img			*del_image(t_mlx *mlx, t_img *img);
t_img			*new_image(t_mlx *mlx);
void			clear_image(t_img *img);
void			set_image_pixel(t_img *image, int x, int y, int color);
int				get_image_pixel(t_img *img, int x, int y);
t_fractal		*get_fractal(char *str);

int				get_color(t_pixel p, t_mlx *mlx);

void			zoom(int x, int y, t_viewport *v, double z);
void			viewport_fit(t_viewport *v);
void			reset_viewport(t_mlx *mlx);
t_complex		screen_to_complex(int x, int y, t_viewport *v);

t_pixel			mandelbrot_pixel(int x, int y, t_viewport *v, t_mlx *mlx);
void			mandelbrot_viewport(t_viewport *v);
t_pixel			burningship_pixel(int x, int y, t_viewport *v, t_mlx *mlx);
void			burningship_viewport(t_viewport *v);
t_pixel			julia_pixel(int x, int y, t_viewport *v, t_mlx *mlx);
void			julia_viewport(t_viewport *v);

int				hook_mousedown(int button, int x, int y, t_mlx *mlx);
int				hook_mouseup(int button, int x, int y, t_mlx *mlx);
int				hook_mousemove(int x, int y, t_mlx *mlx);
int				hook_keydown(int key, t_mlx *mlx);
int				hook_keyup(int key, t_mlx *mlx);
int				handle_draw(int key, t_mlx *mlx);
void			set_render_position(int key, t_mlx *mlx);

int				handle_settings(t_mlx *mlx, t_point m_pos);
void			handle_color_select(t_mlx *mlx, t_point m_pos);
void			toggle_setting(t_mlx *mlx, int setting);

/*
**** Rendering
*/
void			render_settings(t_mlx *mlx);
void			render_settings_text(t_mlx *mlx);
void			render_settings_selected(t_mlx *mlx);
void			render_tips_text(t_mlx *mlx);

/*
**** Drawing
*/
void			draw_rec(t_img *img, t_point pos, t_point size, t_rgba color);
void			draw_color_picker(t_mlx *mlx, t_img *img, t_point pos);
void			draw_fractal(t_mlx *mlx);

/*
**** Data update
*/
void			update_color(t_mlx *mlx);
void			update_zoom(t_mlx *mlx, int x, int y);
void			update_position(t_mlx *mlx, int x, int y);

/*
**** Utils
*/
t_point			point(float x, float y);
#endif
