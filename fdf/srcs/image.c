/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:38:43 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/19 17:49:27 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_image_pixel(t_img *img, int x, int y)
{
	if (x < 0 || x >= img->sx || y < 0 || y >= img->sy)
		return (0);
	return (*(int *)(img->ptr + ((x + y * img->sx) * img->bpp)));
}

void	set_image_pixel(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= img->sx || y < 0 || y >= img->sy)
		return ;
	*(int *)(img->ptr + ((x + y * img->sx) * img->bpp)) = color;
}

void	clear_image(t_mlx *mlx, t_img *img)
{
	if (mlx->settings->advanced)
		ft_memcpy(img->ptr, mlx->background->ptr, mlx->sx * mlx->sy * img->bpp);
	else
		ft_bzero(img->ptr, mlx->sx * mlx->sy * img->bpp);
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
	if ((img->img = mlx_new_image(mlx->mlx, mlx->sx, mlx->sy)) == NULL)
		return (del_image(mlx, img));
	img->ptr = mlx_get_data_addr(img->img, &img->bpp, &img->stride,
			&img->endian);
	img->bpp /= 8;
	img->sx = mlx->sx;
	img->sy = mlx->sy;
	return (img);
}
