/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:04:12 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/07 15:18:53 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *str, int fd)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i])
			ft_putchar_fd(str[i++], fd);
		ft_putchar_fd('\n', fd);
	}
}
