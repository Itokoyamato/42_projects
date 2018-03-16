/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 18:54:34 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/14 18:54:36 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_24to12(int hour)
{
	if (hour > 12)
		hour -= 12;
	if (hour == 0)
		hour = 12;
	return (hour);
}

void	ft_take_place(int hour)
{
	char	*isam1;
	char	*isam2;
	int		todisplay;

	isam1 = "A";
	isam2 = "A";
	todisplay = hour + 1;
	if (hour >= 11)
	{
		if (hour > 23)
		{
			isam1 = "A";
			hour = 0;
		}
		if (hour > 11)
			isam1 = "P";
		if (hour + 1 > 11 && hour + 1 < 24)
			isam2 = "P";
		todisplay = hour + 1;
	}
	hour = ft_24to12(hour);
	todisplay = ft_24to12(todisplay);
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	printf("%d.00 %s.M AND %d.00 %s.M.\n", hour, isam1, todisplay, isam2);
}
