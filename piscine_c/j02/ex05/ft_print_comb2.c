/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 18:58:55 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/07 22:53:15 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb2(void)
{
	int nbr[2];

	nbr[0] = 0;
	nbr[1] = 0;
	while (nbr[0] + nbr[1] < 197)
	{
		if (nbr[0]++ == 99)
		{
			nbr[0] = 0;
			nbr[1]++;
		}
		if (nbr[1] < nbr[0])
		{
			if (nbr[1] != 00 || nbr[0] != 01)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			ft_putchar(nbr[1] / 10 + '0');
			ft_putchar(nbr[1] % 10 + '0');
			ft_putchar(' ');
			ft_putchar(nbr[0] / 10 + '0');
			ft_putchar(nbr[0] % 10 + '0');
		}
	}
}
