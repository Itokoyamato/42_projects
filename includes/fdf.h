/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:51:20 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/13 17:06:26 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# include "libft.h"
# include "mlx.h"
# define FDF_H
# define sX				1280
# define sY				720

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
}					t_vector;
typedef struct		s_map
{
	int			width;
	int			height;
	int			depth_min;
	int			depth_max;
	t_vector	**vectors;
}					t_map;
typedef struct		s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
}					t_mouse;
typedef struct		s_img
{
	void		*img;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
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
	t_rgba		color1;
	t_rgba		color2;
}					t_settings;
typedef struct		s_mlx
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_map		*map;
	t_cam		*cam;
	t_mouse		*mouse;
	double		**zbuf;
	t_settings	*settings;
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

int					parse_map(int fd, t_map **map);
void				fill_colors(t_map *m);
t_vector			*get_vector(int x, int y, char *str);
void				get_depth(t_map *m);

t_img				*new_image(t_mlx *mlx);
t_img				*del_image(t_mlx *mlx, t_img *img);
void				image_set_pixel(t_img *img, int x, int y, int color);
int					image_get_pixel(t_img *img, int x, int y);

void				clear_image(t_img *img);
void				render_fdf(t_mlx *mlx);
int					clerp(int c1, int c2, double p);
t_vector			calc_vec_rotation(t_vector p, t_cam *r);
int					clipping(t_vector *p1, t_vector *p2);

void				render_background(t_mlx *mlx);
void				render_settings(t_mlx *mlx);

t_rgba 				blend(t_rgba fg, t_rgba bg);

t_rgba				hsvtorgba(float h, float s, float v);

t_rgba				rgba(int r, int g, int b, int a);
t_rgba				hextorgba(int hex);
int					rgbatohex(t_rgba c);
#endif