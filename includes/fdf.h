/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:51:20 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/20 15:57:44 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
**** Libs
*/
# include "libft.h"
# include "mlx.h"
# include "typedefs.h"

/*
**** Utils
*/
# define MIN_SX			500
# define MIN_SY			400/16*9
# define MAX_SX			2560
# define MAX_SY			1395

/*
**** Main
*/
int				err(char *err);
t_mlx			*init_fdf(t_mlx *mlx, char *title, t_map *map);
int				init_settings(t_mlx *mlx);

/*
**** Parsing
*/
int				parse_map(int fd, t_mlx *mlx, t_map **map);
void			get_map_minmax_depth(t_map *m);

/*
**** Image
*/
t_img			*new_image(t_mlx *mlx);
t_img			*del_image(t_mlx *mlx, t_img *img);
void			set_image_pixel(t_img *img, int x, int y, int color);
int				get_image_pixel(t_img *img, int x, int y);
void			clear_image(t_mlx *mlx, t_img *img);

/*
**** Vectors
*/
t_vector		*new_vector(int x, int y, char *str);
t_vector		math_vec(t_vector v, t_mlx *mlx);
t_vector		get_vector(t_map *map, int x, int y);

/*
**** Drawing
*/
void			draw_line(t_mlx *mlx, t_vector p1, t_vector p2);
void			draw_rec(t_img *img, t_point pos, t_point size, t_rgba color);
void			draw_color_picker(t_mlx *mlx, t_img *img, t_point pos);

/*
**** Rendering
*/
void			render_fdf(t_mlx *mlx);
void			render_background(t_mlx *mlx);
void			render_settings(t_mlx *mlx);
void			render_settings_text(t_mlx *mlx);

/*
**** Colors
*/
t_rgba			blend(t_rgba fg, t_rgba bg);
t_rgba			hsvtorgba(float h, float s, float v);
t_rgba			rgba(int r, int g, int b, int a);
t_rgba			hextorgba(int hex);
int				rgbatohex(t_rgba c);

int				get_palette_color(t_mlx *mlx, double z, t_map *m, double p);
void			set_map_colors(t_mlx *mlx, t_map *m);

/*
**** Controls
*/
int				hook_mousedown(int button, int x, int y, t_mlx *mlx);
int				hook_mouseup(int button, int x, int y, t_mlx *mlx);
int				hook_mousemove(int x, int y, t_mlx *mlx);
int				hook_keydown(int key, t_mlx *mlx);
int				hook_keyup(int key, t_mlx *mlx);
int				handle_settings(t_mlx *mlx, t_point m_pos);
void			handle_color_select(t_mlx *mlx, t_point m_pos);
void			toggle_setting(t_mlx *mlx, int setting);
void			change_depth(t_mlx *mlx, int i);

/*
**** Data update
*/
void			update_color(t_mlx *mlx);
void			update_rotation(t_mlx *mlx, int x, int y);
void			update_zoom(t_mlx *mlx, int y);
void			update_position(t_mlx *mlx, int x, int y);

/*
**** Utils
*/
t_point			point(float x, float y);
int				clerp(int c1, int c2, double p);
int				is_line_clipping(t_mlx *mlx, t_vector *p1, t_vector *p2);
#endif
