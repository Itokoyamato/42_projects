/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 13:46:14 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/06 23:39:44 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_numbers(void)
{
	char l;

	l = '0';
	while (l <= '9')
	{
		ft_putchar(l);
		l = l + 1;
	}
	ft_putchar('\n');
}
