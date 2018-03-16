/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amacieje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/10 10:11:21 by amacieje          #+#    #+#             */
/*   Updated: 2016/07/10 10:56:01 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	firstline(int x);
void	content(int x, char c);

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
		content(x, 'B');
		y--;
	}
	firstline(x);
}

void	firstline(int x)
{
	write(1, "A", 1);
	while ((x - 2) > 0)
	{
		x--;
		write(1, "B", 1);
	}
	if (x > 1)
		write(1, "C", 1);
	write(1, "\n", 1);
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
