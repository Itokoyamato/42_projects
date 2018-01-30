/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:57:39 by llaporte          #+#    #+#             */
/*   Updated: 2017/03/27 14:59:56 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtoupper(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i++])
		str[i - 1] = ft_toupper(str[i - 1]);
	return (str);
}
