/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:57:47 by llaporte          #+#    #+#             */
/*   Updated: 2017/05/13 16:09:57 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolower(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i++])
		str[i - 1] = ft_tolower(str[i - 1]);
	return (&str[0]);
}
