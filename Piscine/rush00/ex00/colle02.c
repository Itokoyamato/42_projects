/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 13:58:07 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/09 14:24:02 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_cornerline(int x, char c, char c2);
void	print_content(int x, char c);
void	ft_putchar(char c);

void	colle(int x, int y)
{
	if ((x < 1) || (y < 1))
	{
		write(1, "mauvaises valeurs", 17);
		return ;
	}
	if (y >= 2)
		print_cornerline(x, 'A', 'B');
	while ((y - 2) > 0)
	{
		print_content(x, 'B');
		y--;
	}
	if (y >= 2)
		print_cornerline(x, 'C', 'B');
	else
		print_cornerline(x, 'A', 'B');
}

void	print_cornerline(int x, char c, char c2)
{
	if (x > 1)
		write(1, &c, 1);
	while ((x - 2) > 0)
	{
		x--;
		write(1, &c2, 1);
	}
	write(1, &c, 2);
	write(1, "\n", 2);
}

void	print_content(int x, char c)
{
	if (x > 1)
		write(1, &c, 1);
	while ((x - 2) > 0)
	{
		x--;
		write(1, " ", 1);
	}
	write(1, &c, 1);
	write(1, "\n", 1);
}
