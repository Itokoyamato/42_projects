/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 16:34:48 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/23 22:27:41 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		check_lines_size(char *str, int l_size)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (k == l_size)
		{
			if (str[i] == '\n')
			{
				k = 0;
				i++;
				continue;
			}
			else
				return (0);
		}
		k++;
		i++;
	}
	return (1);
}

int		check_characters(char *str, int i)
{
	if (str[i] == 'o' || str[i] == '-' || str[i] == '|' || str[i] == ' ' ||
			str[i] == '/' || str[i] == '\\' || str[i] == '*' || str[i] == 'A' ||
			str[i] == 'B' || str[i] == 'C' || str[i] == '\n')
		return (1);
	return (0);
}

int		is_valid(char *str, int *l, int *h)
{
	int		i;
	int		nl_count;
	int		l_size;

	i = 0;
	nl_count = 0;
	l_size = 0;
	while (str[i])
	{
		if (check_characters(str, i))
		{
			if (str[i] == '\n')
				nl_count++;
		}
		else
			return (0);
		i++;
	}
	l_size = (ft_strlen(str) - nl_count) / nl_count;
	if (!(check_lines_size(str, l_size)))
		return (0);
	*l = l_size;
	*h = nl_count;
	return (1);
}
