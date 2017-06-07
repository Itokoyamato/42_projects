/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 15:24:40 by dthuilli          #+#    #+#             */
/*   Updated: 2017/06/07 10:48:49 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_image_pixel(t_img *img, int x, int y)
{
	if (x < 0 || x >= SX || y < 0 || y >= SY)
		return (0);
	return (*(int *)(img->ptr + ((x + y * SX) * img->bpp)));
}

void	set_image_pixel(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= SX || y < 0 || y >= SY)
		return ;
	*(int *)(img->ptr + ((x + y * SX) * img->bpp)) = color;
}

void	clear_image(t_img *img)
{
	ft_bzero(img->ptr, SX * SY * img->bpp);
}

t_img	*del_image(t_mlx *mlx, t_img *img)
{
	if (img != NULL)
	{
		if (img->img != NULL)
			mlx_destroy_image(mlx->mlx, img->img);
		ft_memdel((void **)&img);
	}
	return (NULL);
}

t_img	*new_image(t_mlx *mlx)
{
	t_img		*img;

	if ((img = ft_memalloc(sizeof(t_img))) == NULL)
		return (NULL);
	if ((img->img = mlx_new_image(mlx->mlx, SX, SY)) == NULL)
		return (del_image(mlx, img));
	img->ptr = mlx_get_data_addr(img->img, &img->bpp, &img->stride,
			&img->endian);
	img->bpp /= 8;
	return (img);
}
