/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:07:19 by llaporte          #+#    #+#             */
/*   Updated: 2017/05/15 18:25:42 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		rekt_percents2(t_dataprintf *dt, int i)
{
	if ((dt->str[i] == 'h' && dt->str[i + 1] == 'h') ||
		(dt->str[i] == 'l' && dt->str[i + 1] == 'l'))
		i += 2;
	else if ((dt->str[i] == 'h') || (dt->str[i] == 'l') ||
		(dt->str[i] == 'j') || (dt->str[i] == 'z'))
		++i;
	if (dt->str[i] == '%')
		dt->str[i] = '@';
	return (1);
}

int				rekt_percents(t_dataprintf *dt)
{
	int		i;

	i = 0;
	while (dt->str[i++])
		if (dt->str[i - 1] == '%')
		{
			while (dt->str[i] == '#' || dt->str[i] == '0' ||
				dt->str[i] == '-' || dt->str[i] == '+' || dt->str[i] == ' ')
				++i;
			while (ft_isdigit(dt->str[i]))
				++i;
			if (dt->str[i] == '.')
				++i;
			while (ft_isdigit(dt->str[i]))
				++i;
			if (!(rekt_percents2(dt, i)))
				return (0);
		}
	dt->cur_pcs = 0;
	return (1);
}

void			printf_putlm(t_dataprintf *dt)
{
	if ((dt->str[dt->i] == 'h' && dt->str[dt->i + 1] != 'h') ||
		(dt->str[dt->i] == 'l' && dt->str[dt->i + 1] != 'l'))
		dt->length_mod[dt->cur_pcs++] = dt->str[dt->i];
	else if ((dt->str[dt->i] == 'h' && dt->str[dt->i + 1] == 'h') ||
		(dt->str[dt->i] == 'l' && dt->str[dt->i + 1] == 'l'))
		dt->length_mod[dt->cur_pcs++] = ft_toupper(dt->str[dt->i]);
	else if (dt->str[dt->i] == 'j' || dt->str[dt->i] == 'z')
		dt->length_mod[dt->cur_pcs++] = dt->str[dt->i];
	else
		dt->length_mod[dt->cur_pcs++] = '0';
}

void			printf_set_flags(t_dataprintf *dt, int i, int j)
{
	j = j + '0';
	if (dt->str[i] == '#')
		FH = 1;
	else if (dt->str[i] == '0')
		FZ = 1;
	else if (dt->str[i] == '-')
		FM = 1;
	else if (dt->str[i] == '+')
		FP = 1;
	else if (dt->str[i] == ' ')
		FS = 1;
}
