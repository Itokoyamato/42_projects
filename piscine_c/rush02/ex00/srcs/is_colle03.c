/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_colle03.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 09:31:23 by thninh            #+#    #+#             */
/*   Updated: 2016/07/24 09:56:14 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "functions.h"

int		check_first_line03(char *str, int *l)
{
	int i;
	int count;

	i = 1;
	count = ft_strlen(str);
	if (*l == 1 && str[0] == 'A')
		return (1);
	if (str[0] != 'A' || str[*l - 1] != 'C')
	{
		return (0);
	}
	while (i < *l - 1 && count > 2)
	{
		if (str[i] != 'B')
			return (0);
		i++;
	}
	return (1);
}

int		check_content03(char *str, int *l, int *h)
{
	int i;
	int count;

	i = *l;
	count = ft_strlen(str);
	if (*h < 3)
		return (1);
	while (i < count - *l - 2)
	{
		if (str[i] == '\n')
			i++;
		if ((str[i - 1] == '\n' && str[i] != 'B') ||
				(str[i + 1] == '\n' && str[i] != 'B'))
			return (0);
		else if ((str[i - 1] == '\n' && str[i] == 'B') ||
				(str[i + 1] == '\n' && str[i] == 'B'))
		{
			i++;
			continue;
		}
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int		check_last_line03(char *str, int *l, int *h)
{
	int i;
	int count;

	count = ft_strlen(str);
	i = count - *l;
	if (*h < 2)
		return (1);
	if (*h == 2 && str[*l + 1] == 'A')
		return (1);
	if (*l == 1 && str[i - 1] == 'A')
		return (1);
	if (str[count - *l - 1] != 'A' || str[count - 2] != 'C')
		return (0);
	while (i < count - 2 && count > 2)
	{
		if (str[i] != 'B')
			return (0);
		i++;
	}
	return (1);
}

int		is_colle03(char *str, int *l, int *h)
{
	if (!(check_first_line03(str, l) && check_content03(str, l, h) &&
				check_last_line03(str, l, h)))
		return (0);
	return (1);
}
