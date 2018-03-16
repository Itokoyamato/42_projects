/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:35:40 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/10 16:09:37 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	if (size > 0)
	{
		mem = malloc(size);
		if (mem)
		{
			ft_bzero(mem, size);
			return (mem);
		}
	}
	return (NULL);
}
