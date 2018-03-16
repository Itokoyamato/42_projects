/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:53:00 by dthuilli          #+#    #+#             */
/*   Updated: 2017/01/09 15:50:03 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
	|| *str == '\r' || *str == ' ')
		++str;
	if (!ft_isdigit(*str))
	{
		if (*str == '-')
			sign = -1;
		else if (*str != '+')
			return (0);
		str++;
	}
	while (ft_isdigit(*str))
		result = result * 10 + (*str++ - '0') * sign;
	return (result);
}
