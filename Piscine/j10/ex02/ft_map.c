/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 09:05:47 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/18 09:11:02 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*ft_map(int *tab, int lenght, int (*f)(int))
{
	int		i;
	int		*array;

	i = 0;
	array = (int*)malloc(sizeof(*tab) * lenght);
	while (i < lenght)
	{
		array[i] = f(tab[i]);
		i++;
	}
	return (array);
}
