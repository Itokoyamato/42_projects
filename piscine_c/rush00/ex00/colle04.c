/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acouturi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 18:53:01 by acouturi          #+#    #+#             */
/*   Updated: 2016/07/09 19:10:35 by acouturi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	firstline(int x);
void	content(int x, char c);
void	lastline(int x);
void	ft_putchar(char c);

void	colle(int x, int y)
{
	int n;

	n = y;
	if ((x < 1) || (y < 1))
	{
		write(1, "mauvaises valeurs", 17);
		return ;
	}
	firstline(x);
	while ((n - 2) > 0)
	{
		content(x, 'B');
		n--;
	}
	if (y >= 2)
		lastline(x);
}

void	firstline(int x)
{
	int n;

	n = x;
	write(1, "A", 1);
	while ((n - 2) > 0)
	{
		n--;
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

void	lastline(int x)
{
	int n;

	n = x;
	write(1, "C", 1);
	while (x > 2)
	{
		x--;
		write(1, "B", 1);
	}
	if (x > 1)
		write(1, "A", 1);
	write(1, "\n", 1);
}
