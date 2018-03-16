/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:06:59 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/02 16:13:37 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*array;
	int		i;

	if (min >= max)
		return (0);
	array = (int*)malloc(sizeof(array) * (max - min));
	i = min;
	while (i < max)
	{
		array[i - min] = i;
		i++;
	}
	return (array);
}
