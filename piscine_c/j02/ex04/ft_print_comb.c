/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 16:18:24 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/06 23:40:06 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb(void)
{
	char nbr[3];

	nbr[0] = '0';
	while (nbr[0] <= '7')
	{
		nbr[1] = nbr[0] + 1;
		while (nbr[1] <= '8')
		{
			nbr[2] = nbr[1] + 1;
			while (nbr[2] <= '9')
			{
				ft_putchar(nbr[0]);
				ft_putchar(nbr[1]);
				ft_putchar(nbr[2]);
				if (nbr[0] != '7')
					ft_putchar(',');
				if (nbr[0] != '7')
					ft_putchar(' ');
				nbr[2]++;
			}
			nbr[1]++;
		}
		nbr[0]++;
	}
}
