/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:38:43 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/17 17:05:07 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_image_pixel(t_img *img, int x, int y)
{
	if (x < 0 || x >= img->sX || y < 0 || y >= img->sY)
		return (0);
	return (*(int *)(img->ptr + ((x + y * img->sX) * img->bpp)));
}

void	set_image_pixel(t_img *img, int x, int y, int color)
{
	if (x < 0 || x >= img->sX || y < 0 || y >= img->sY)
		return ;
	*(int *)(img->ptr + ((x + y * img->sX) * img->bpp)) = color;
}

void	clear_image(t_mlx *mlx, t_img *img)
{
	ft_memcpy(img->ptr, mlx->background->ptr, mlx->sX * mlx->sY * img->bpp);
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
	if ((img->img = mlx_new_image(mlx->mlx, mlx->sX, mlx->sY)) == NULL)
		return (del_image(mlx, img));
	img->ptr = mlx_get_data_addr(img->img, &img->bpp, &img->stride,
			&img->endian);
	img->bpp /= 8;
	img->sX = mlx->sX;
	img->sY = mlx->sY;
	return (img);
}
