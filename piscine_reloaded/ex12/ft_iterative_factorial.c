/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 14:23:34 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/02 14:29:37 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int i;
	int c;

	i = 1;
	c = 1;
	if (nb < 0 || nb > 12)
		return (0);
	while (i <= nb)
	{
		c = c * i;
		i++;
	}
	nb = c;
	return (nb);
}
