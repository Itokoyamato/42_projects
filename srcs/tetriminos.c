/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:50:57 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/15 15:24:55 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char **t1(void)
{
	char **result;

	result = (char **)ft_strnew(4);
	if (!result)
		return (0)
	result[0] = "....\0";
	result[1] = "..##\0";
	result[2] = "..#.\0";
	result[3] = "..#.\0";
	return (result);
}

int	whichTetri(char **t)
{

	if (str)
}
