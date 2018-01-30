/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:52:37 by llaporte          #+#    #+#             */
/*   Updated: 2017/03/02 16:36:14 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int result;
	int is_negative;

	i = 0;
	is_negative = 0;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	is_negative = str[i] == '-' ? 1 : 0;
	i = str[i] == '+' || str[i] == '-' ? i + 1 : i;
	while (ft_isdigit(str[i]))
		result = result * 10 + (str[i++] - 48);
	result = is_negative == 1 ? result * -1 : result;
	return (result);
}
