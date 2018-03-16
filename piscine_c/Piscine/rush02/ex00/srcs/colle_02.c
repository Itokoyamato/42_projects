/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 16:43:40 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/23 22:28:02 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "functions.h"

void	colle_2(char *str)
{
	int		*l;
	int		*h;
	int		lenght;
	int		height;

	lenght = 0;
	height = 0;
	l = &lenght;
	h = &height;
	if (is_valid(str, l, h))
		check_colle(str, l, h);
	else
		ft_putstr("aucune");
}
