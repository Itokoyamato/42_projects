/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:26:14 by dthuilli          #+#    #+#             */
/*   Updated: 2017/06/07 10:48:45 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H
# include <stdint.h>

typedef struct			s_point
{
	float				x;
	float				y;
}						t_point;
typedef struct			s_rgba
{
	uint8_t				b;
	uint8_t				g;
	uint8_t				r;
	uint8_t				a;
}						t_rgba;

typedef union			u_color
{
	int					value;
	t_rgba				rgba;
}						t_color;

typedef struct			s_mouse
{
	char				isdown;
	int					x;
	int					y;
	int					lastx;
	int					lasty;
}						t_mouse;

typedef struct			s_img
{
	void				*img;
	char				*ptr;
	int					bpp;
	int					stride;
	int					endian;
}						t_img;

typedef struct			s_complex
{
	double				r;
	double				i;
}						t_complex;

typedef struct			s_viewport
{
	double				xmin;
	double				xmax;
	double				ymin;
	double				ymax;
	double				zoom;
	double				offx;
	double				offy;
	long				max;
	t_complex			mouse;
}						t_viewport;

typedef struct			s_pixel
{
	t_complex			c;
	long				i;
}						t_pixel;

typedef struct s_mlx	t_mlx;

typedef void			(*t_f_fn_v)(t_viewport *v);
typedef t_pixel			(*t_f_fn_p)(int x, int y, t_viewport *v, t_mlx *mlx);
typedef struct			s_fractal
{
	char				*name;
	t_f_fn_v			viewport;
	t_f_fn_p			pixel;
	int					mouse;
}						t_fractal;

typedef struct			s_settings
{
	t_point				p_pos;
	float				p_hue;
	float				p_sat;
	float				p_val;
	t_point				c1_pos;
	t_point				c2_pos;
	t_point				c3_pos;
	t_point				c4_pos;
	t_rgba				colors[5];
	t_point				c5_pos;
	int					selected;
	int					display;
	int					tips;
	int					smooth;
	int					mouselock;
}						t_settings;
typedef struct			s_controls
{
	int					isdown[275];
	int					m_x;
	int					m_y;
	int					m_lastx;
	int					m_lasty;
}						t_controls;

struct					s_mlx
{
	void				*mlx;
	void				*window;
	t_fractal			*fractal;
	t_pixel				*data;
	t_img				*img;
	t_mouse				mouse;
	t_viewport			viewport;
	t_settings			*settings;
	t_controls			*controls;
};
typedef struct			s_pqt
{
	float				p;
	float				q;
	float				t;
	float				v;
}						t_pqt;
#endif
