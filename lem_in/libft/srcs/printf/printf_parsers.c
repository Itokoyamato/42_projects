/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_parsers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:52:36 by llaporte          #+#    #+#             */
/*   Updated: 2017/05/16 12:33:22 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		parse_precisions(t_dataprintf *dt)
{
	int		i;
	void	*tofree;

	i = 0;
	while (dt->str[i++])
		if (dt->str[i - 1] == '%')
		{
			while (ft_isdigit(dt->str[i]))
				++i;
			if (dt->str[i] == '.')
			{
				dt->precisions[dt->cur_pcs++] = ft_atoi(&dt->str[i + 1]);
				tofree = dt->str;
				if (!(dt->str = ft_strerase(dt->str, i, ft_isdigit(dt->str[i +
					1]) ? ft_nbdigit(dt->precisions[dt->cur_pcs - 1]) + 1 : 1)))
					return (0);
				free(tofree);
			}
			else
				dt->precisions[dt->cur_pcs++] = -1;
		}
	dt->cur_pcs = 0;
	return (1);
}

int		parse_flags(t_dataprintf *dt)
{
	int		i;
	int		j;
	void	*tofree;

	i = 0;
	while (dt->str[i++])
		if (dt->str[i - 1] == '%')
		{
			j = 0;
			while (dt->str[i] == '#' || dt->str[i] == '0' ||
				dt->str[i] == '-' || dt->str[i] == '+' || dt->str[i] == ' ')
				printf_set_flags(dt, i++, j++);
			if (j > 0)
			{
				tofree = dt->str;
				if (!(dt->str = ft_strerase(dt->str, i - j, j)))
					return (0);
				free(tofree);
			}
			dt->cur_pcs++;
		}
	dt->cur_pcs = 0;
	return (1);
}

int		parse_minlenght(t_dataprintf *dt)
{
	int		i;
	void	*tofree;

	i = 0;
	while (dt->str[i++])
		if (dt->str[i - 1] == '%')
		{
			if (ft_isdigit(dt->str[i]) && dt->str[i] != '0')
			{
				dt->minimum_lenght[dt->cur_pcs++] = ft_atoi(&dt->str[i]);
				tofree = dt->str;
				if (!(dt->str = ft_strerase(dt->str, i,
					ft_nbdigit(dt->minimum_lenght[dt->cur_pcs - 1]))))
					return (0);
				free(tofree);
			}
			else
				dt->minimum_lenght[dt->cur_pcs++] = -1;
		}
	dt->cur_pcs = 0;
	return (1);
}

int		parse_lengthmod(t_dataprintf *dt)
{
	void	*tofree;

	while (dt->str[dt->i++])
		if (dt->str[dt->i - 1] == '%')
		{
			printf_putlm(dt);
			if (dt->length_mod[dt->cur_pcs - 1] != '0')
			{
				tofree = dt->str;
				if (!(dt->str = ft_strerase(dt->str, dt->i,
				ft_isupper(dt->length_mod[dt->cur_pcs - 1]) ? 2 : 1)))
					return (0);
				free(tofree);
			}
		}
	dt->cur_pcs = 0;
	dt->i = 0;
	return (1);
}

int		prepare_parse(t_dataprintf *dt)
{
	dt->nbcv = 0;
	if (!(rekt_percents(dt)))
		return (0);
	while (dt->str[dt->i++])
		if (dt->str[dt->i - 1] == '%')
			++dt->nbcv;
	if (!(dt->length_mod = (char *)ft_strnew(sizeof(char) * dt->nbcv)))
		return (0);
	if (!(dt->minimum_lenght = (int *)ft_memalloc(sizeof(int) * dt->nbcv + 1)))
		return (0);
	if (!(dt->precisions = (int *)ft_memalloc(sizeof(int) * dt->nbcv + 1)))
		return (0);
	if (!(dt->flag_hash = (int *)ft_memalloc(sizeof(int) * dt->nbcv + 1)))
		return (0);
	if (!(dt->flag_zero = (int *)ft_memalloc(sizeof(int) * dt->nbcv + 1)))
		return (0);
	if (!(dt->flag_minu = (int *)ft_memalloc(sizeof(int) * dt->nbcv + 1)))
		return (0);
	if (!(dt->flag_plus = (int *)ft_memalloc(sizeof(int) * dt->nbcv + 1)))
		return (0);
	if (!(dt->flag_spac = (int *)ft_memalloc(sizeof(int) * dt->nbcv + 1)))
		return (0);
	dt->i = 0;
	return (1);
}
