/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 10:27:12 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/10 10:52:35 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	firstline(int x);
void	content(int x, char c);
void	ft_putchar(char c);

void	colle(int x, int y)
{
	if ((x < 1) || (y < 1))
	{
		write(1, "mauvaises valeurs", 17);
		return ;
	}
	if (y >= 2)
		firstline(x);
	while ((y - 2) > 0)
	{
		content(x, '|');
		y--;
	}
	firstline(x);
}

void	firstline(int x)
{
	if (x > 1)
		write(1, "o", 1);
	while ((x - 2) > 0)
	{
		x--;
		write(1, "-", 1);
	}
	write(1, "o\n", 2);
}

void	content(int x, char c)
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
