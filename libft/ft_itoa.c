/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:16:43 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/10 14:31:41 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nblen(int nb)
{
	int	len;

	len = 2;
	if (nb < 0)
	{
		nb *= -1;
		len += 1;
	}
	while (nb /= 10)
		++len;
	return (len);
}

static void		do_itoa(long int nbr, char *str, int *index)
{
	if (nbr > 9)
		do_itoa(nbr / 10, str, index);
	str[(*index)++] = '0' + nbr % 10;
}

char			*ft_itoa(int n)
{
	char		*str;
	int			index;
	long int	nbr;

	index = 0;
	nbr = (long int)n;
	if (!(str = (char*)malloc(sizeof(char) * nblen(n))))
		return (0);
	if (nbr < 0)
		str[index++] = '-';
	do_itoa(ABS(nbr), str, &index);
	str[index] = '\0';
	return (str);
}
