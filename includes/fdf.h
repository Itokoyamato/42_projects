/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:51:20 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/18 15:51:20 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# include "libft.h"
# include "mlx.h"
# define FDF_H
# define minsX			400
# define minsY			400/16*9
# define maxsX			2560
# define maxsY			1395

typedef struct		s_point
{
	float		x;
	float		y;
}					t_point;
typedef struct		s_cam
{
	double		offsetx;
	double		offsety;
	double		x;
	double		y;
	int			scale;
	double		**matrix;
}					t_cam;
typedef struct		s_vector
{
	double		x;
	double		y;
	double		z;
	int			color;
	int			sX;
	int			sY;
}					t_vector;
typedef struct		s_map
{
	int			width;
	int			height;
	int			depth_min;
	int			depth_max;
	t_vector	**vectors;
}					t_map;
typedef struct		s_img
{
	void		*img;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
	int			sX;
	int			sY;
}					t_img;
typedef struct		s_rgba
{
	float		r;
	float		g;
	float		b;
	float		a;
}					t_rgba;
typedef struct		s_settings
{
	t_point		p_pos;
	float		p_hue;
	float		p_sat;
	float		p_val;
	t_rgba		bg_c1;
	t_point		bg_c1_pos;
	t_rgba		bg_c2;
	t_point		bg_c2_pos;
	t_rgba		c1;
	t_point		c1_pos;
	t_rgba		c2;
	t_point		c2_pos;
	t_rgba		c3;
	t_point		c3_pos;
	t_rgba		c4;
	t_point		c4_pos;
	t_rgba		c5;
	t_point		c5_pos;
	t_rgba		c6;
	t_point		c6_pos;
	int			selected;
}					t_settings;
typedef struct		s_controls
{
	int			isdown[275];
	int			m_x;
	int			m_y;
	int			m_lastx;
	int			m_lasty;
}					t_controls;
typedef struct		s_mlx
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_img		*background;
	t_map		*map;
	t_cam		*cam;
	t_controls	*controls;
	double		**zbuf;
	t_settings	*settings;
	int			sX;
	int			sY;
}					t_mlx;
typedef struct		s_line
{
	t_vector	start;
	t_vector	stop;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			err2;
}					t_line;
typedef struct		s_pqt
{
	float		p;
	float		q;
	float		t;
	float		v;
}					t_pqt;

int					err(char *err);
t_mlx				*init_fdf(char *title, t_map *map);

int					parse_map(int fd, t_map **map);
void				set_map_colors(t_map *m);
void				get_map_minmax_depth(t_map *m);

t_img				*new_image(t_mlx *mlx);
t_img				*del_image(t_mlx *mlx, t_img *img);
void				set_image_pixel(t_img *img, int x, int y, int color);
int					get_image_pixel(t_img *img, int x, int y);
void				clear_image(t_mlx *mlx, t_img *img);

t_vector			*new_vector(int x, int y, char *str);
t_vector			math_vec(t_vector v, t_mlx *mlx);
t_vector			math_vec_rotation(t_vector p, t_cam *r);
t_vector			get_vector(t_map *map, int x, int y);

void				draw_line(t_mlx *mlx, t_vector p1, t_vector p2);
int					clerp(int c1, int c2, double p);
int					is_line_clipping(t_mlx *mlx, t_vector *p1, t_vector *p2);

void				render_fdf(t_mlx *mlx);
void				render_background(t_mlx *mlx);
void				render_settings(t_mlx *mlx);

t_rgba 				blend(t_rgba fg, t_rgba bg);
t_rgba				hsvtorgba(float h, float s, float v);
t_rgba				rgba(int r, int g, int b, int a);
t_rgba				hextorgba(int hex);
int					rgbatohex(t_rgba c);

int					get_palette_color(double z, t_map *m, double percent);
void				set_map_colors(t_map *m);

int					hook_mousedown(int button, int x, int y, t_mlx *mlx);
int					hook_mouseup(int button, int x, int y, t_mlx *mlx);
int					hook_mousemove(int x, int y, t_mlx *mlx);
int					hook_keydown(int key, t_mlx *mlx);
int					hook_keyup(int key, t_mlx *mlx);
int					handle_settings(t_mlx *mlx, t_point m_pos);

void				update_color(t_mlx *mlx);
void				update_rotation(t_mlx *mlx, int x, int y);
void				update_zoom(t_mlx *mlx, int y);
void				update_position(t_mlx *mlx, int x, int y);

t_point				point(float x, float y);
void				draw_rec(t_img *img, t_point pos, t_point size, t_rgba color);
void				draw_color_picker(t_mlx *mlx, t_img *img, t_point pos);
#endif