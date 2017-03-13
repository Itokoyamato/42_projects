/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_colle01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 09:23:43 by thninh            #+#    #+#             */
/*   Updated: 2016/07/24 14:49:42 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "functions.h"

int		check_first_line01(char *str, int *l)
{
	int i;
	int count;

	i = 1;
	count = ft_strlen(str);
	if (*l == 1 && str[0] == '/')
		return (1);
	if (str[0] != '/' || str[*l - 1] != '\\')
		return (0);
	while (i < *l - 1 && count > 2)
	{
		if (str[i] != '*')
			return (0);
		i++;
	}
	return (1);
}

int		check_content01(char *str, int *l, int *h)
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
		if ((str[i - 1] == '\n' && str[i] != '*') ||
				(str[i + 1] == '\n' && str[i] != '*'))
			return (0);
		else if ((str[i - 1] == '\n' && str[i] == '*') ||
				(str[i + 1] == '\n' && str[i] == '*'))
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

int		check_last_line01(char *str, int *l, int *h)
{
	int i;
	int count;

	count = ft_strlen(str);
	i = count - *l;
	if (*h < 2)
		return (1);
	if (*l == 1 && str[count - *l - 1] == '\\')
		return (1);
	if (str[count - *l - 1] != '\\' || str[count - 2] != '/')
		return (0);
	while (i < count - 2 && count > 2)
	{
		if (str[i] != '*')
			return (0);
		i++;
	}
	return (1);
}

int		is_colle01(char *str, int *l, int *h)
{
	if (!(check_first_line01(str, l) && check_content01(str, l, h) &&
				check_last_line01(str, l, h)))
		return (0);
	return (1);
}
