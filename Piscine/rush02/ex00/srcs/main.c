/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 17:10:03 by jmichaud          #+#    #+#             */
/*   Updated: 2016/07/24 18:09:13 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "functions.h"

int			main(int argc, char **argv)
{
	char	*str;

	(void)argv;
	if (argc == 1)
	{
		str = get_string();
		if (str)
			colle_2(str);
		else
			ft_putstr("malloc() failed: please try again");
	}
	else
		ft_putstr("aucune");
	ft_putchar('\n');
	return (0);
}
