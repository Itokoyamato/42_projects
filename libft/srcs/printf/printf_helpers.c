/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:36:56 by llaporte          #+#    #+#             */
/*   Updated: 2017/05/16 18:08:49 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ad(t_dataprintf *dt, int toaddi, char *towrite)
{
	dt->count += ft_strlen(towrite);
	dt->i += toaddi;
	ft_putstr(towrite);
	free(towrite);
}

void		adc(t_dataprintf *dt, int toaddc, int toaddi, char towrite)
{
	dt->count += toaddc;
	dt->i += toaddi;
	ft_putchar(towrite);
}

void		printf_cleaner(t_dataprintf *dt)
{
	free(dt->length_mod);
	free(dt->minimum_lenght);
	free(dt->precisions);
	free(dt->flag_hash);
	free(dt->flag_zero);
	free(dt->flag_minu);
	free(dt->flag_plus);
	free(dt->flag_spac);
	free(dt->str);
	free(dt);
}

size_t		ft_wstrlenp(wchar_t const *str, int pcs)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] <= 0x7F && (int)size + 1 <= pcs)
			size++;
		else if (str[i] <= 0x7FF && (int)size + 2 <= pcs)
			size += 2;
		else if (str[i] <= 0xFFFF && (int)size + 3 <= pcs)
			size += 3;
		else if (str[i] <= 0x10FFFF && (int)size + 4 <= pcs)
			size += 4;
		else
			return (size);
		i++;
	}
	return (size);
}
