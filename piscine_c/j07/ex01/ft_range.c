/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 12:36:53 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/13 12:36:55 by dthuilli         ###   ########.fr       */
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
