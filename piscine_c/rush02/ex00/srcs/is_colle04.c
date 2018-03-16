/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_colle04.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 16:47:25 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/24 14:50:18 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "functions.h"

int		check_first_line04(char *str, int *l)
{
	int i;
	int count;

	i = 1;
	count = ft_strlen(str);
	if (*l == 1 && str[0] == 'A')
		return (1);
	if (*l == 2 && str[0] == 'A' && str[2] == 'C')
		return (1);
	if (str[0] != 'A' || str[*l - 1] != 'C')
		return (0);
	while (i < *l - 1 && count > 2)
	{
		if (str[i] != 'B')
			return (0);
		i++;
	}
	return (1);
}

int		check_content04(char *str, int *l, int *h)
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

int		check_last_line04(char *str, int *l, int *h)
{
	int i;
	int count;

	count = ft_strlen(str);
	i = count - *l;
	if (*h < 2)
		return (1);
	if (*h == 2 && str[*l + 1] == 'C')
		return (1);
	if (*l == 1 && str[count - *l - 1] == 'C')
		return (1);
	if (str[count - *l - 1] != 'C' || str[count - 2] != 'A')
		return (0);
	while (i < count - 2 && count > 2)
	{
		if (str[i] != 'B')
			return (0);
		i++;
	}
	return (1);
}

int		is_colle04(char *str, int *l, int *h)
{
	if (!(check_first_line04(str, l) && check_content04(str, l, h) &&
				check_last_line04(str, l, h)))
		return (0);
	return (1);
}
