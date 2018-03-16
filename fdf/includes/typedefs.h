/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:46:46 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/19 18:04:19 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

typedef struct	s_point
{
	float		x;
	float		y;
}				t_point;
typedef struct	s_cam
{
	double		offsetx;
	double		offsety;
	double		x;
	double		y;
	int			scale;
	double		**matrix;
}				t_cam;
typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
	int			color;
	int			sx;
	int			sy;
}				t_vector;
typedef struct	s_map
{
	int			width;
	int			height;
	int			depth_min;
	int			depth_max;
	t_vector	**vectors;
}				t_map;
typedef struct	s_img
{
	void		*img;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
	int			sx;
	int			sy;
}				t_img;
typedef struct	s_rgba
{
	float		r;
	float		g;
	float		b;
	float		a;
}				t_rgba;
typedef struct	s_settings
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
	int			display;
	int			advanced;
	int			tips;
	int			depth_multiplier;
}				t_settings;
typedef struct	s_controls
{
	int			isdown[275];
	int			m_x;
	int			m_y;
	int			m_lastx;
	int			m_lasty;
}				t_controls;
typedef struct	s_mlx
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
	int			sx;
	int			sy;
}				t_mlx;
typedef struct	s_line
{
	t_vector	start;
	t_vector	stop;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			err2;
}				t_line;
typedef struct	s_pqt
{
	float		p;
	float		q;
	float		t;
	float		v;
}				t_pqt;
#endif
