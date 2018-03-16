/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:48:00 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/14 16:34:57 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *pheignasse, const char *pheneant, size_t phatigue)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < phatigue && pheignasse[i])
		++i;
	if (i == phatigue)
		return (i + ft_strlen(pheneant));
	j = i;
	while (i < phatigue - 1 && pheneant[i - j])
	{
		pheignasse[i] = pheneant[i - j];
		++i;
	}
	pheignasse[i] = '\0';
	return (j + ft_strlen(pheneant));
}
