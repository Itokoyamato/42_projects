/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv_general.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:58:21 by llaporte          #+#    #+#             */
/*   Updated: 2017/05/18 17:50:51 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		for_cc(t_dataprintf *dt)
{
	wchar_t	arg;

	arg = va_arg(dt->arguments, wchar_t);
	if (CI == 'C' || LM == 'l')
	{
		while (ML-- - (int)ft_wcharsize(arg) > 0 && !FM)
			adc(dt, 1, 0, FZ ? '0' : ' ');
		dt->count += ft_wcharsize(arg);
		ft_putwchar(arg);
		while (ML-- + 1 - (int)ft_wcharsize(arg) > 0 && FM)
			adc(dt, 1, 0, FZ ? '0' : ' ');
	}
	else
	{
		while (ML-- - 1 > 0 && !FM)
			adc(dt, 1, 0, FZ ? '0' : ' ');
		adc(dt, 1, 0, arg);
		while (ML-- > 0 && FM)
			adc(dt, 1, 0, FZ ? '0' : ' ');
	}
	return (1);
}

int		for_sl(t_dataprintf *dt)
{
	wchar_t			*arg;
	int				i;

	arg = va_arg(dt->arguments, wchar_t *);
	if (arg || ML != -1)
	{
		if (PCS == -1 && arg)
			PCS = (int)ft_wstrlen(arg);
		else if (arg)
			PCS = (int)ft_wstrlenp(arg, PCS);
		while (ML-- - PCS > 0 && !FM)
			adc(dt, 1, 0, FZ ? '0' : ' ');
		i = 0;
		while (arg && *arg && i + (int)ft_wcharsize(*arg) <= PCS)
		{
			dt->count += ft_wcharsize(*arg);
			i += ft_wcharsize(*arg);
			ft_putwchar(*arg++);
		}
	}
	else
		ad(dt, 0, ft_strsub("(null)", 0, PCS > 0 ? PCS : 6));
	while (ML-- + 1 - PCS > 0 && FM)
		adc(dt, 1, 0, FZ ? '0' : ' ');
	return (1);
}

int		for_ss(t_dataprintf *dt)
{
	char			*arg;
	int				i;

	if (CI == 'S' || LM == 'l' || LM == 'L')
		return (for_sl(dt));
	arg = va_arg(dt->arguments, char *);
	if (arg || ML != -1)
	{
		PCS = !(PCS == -1) && PCS < (int)ft_strlen(arg) ?
			PCS : (int)ft_strlen(arg);
		while (ML-- - PCS > 0 && !FM)
			adc(dt, 1, 0, FZ ? '0' : ' ');
		i = 0;
		if (arg)
			while (arg[i] && i < PCS)
				adc(dt, 1, 0, arg[i++]);
		while (ML-- + 1 - PCS > 0 && FM)
			adc(dt, 1, 0, FZ ? '0' : ' ');
	}
	else
		ad(dt, 0, ft_strsub("(null)", 0, PCS > 0 ? PCS : 6));
	return (1);
}

int		for_nimp(t_dataprintf *dt)
{
	while (ML-- - 1 > 0 && !FM)
		adc(dt, 1, 0, FZ ? '0' : ' ');
	if (CI == '@')
		adc(dt, 1, 0, '%');
	else if (CI)
		adc(dt, 1, 0, CI);
	while (ML-- > 0 && FM)
		adc(dt, 1, 0, ' ');
	return (1);
}

int		printf_conversion(t_dataprintf *dt)
{
	int i;

	if (CI == 's' || CI == 'S')
		i = for_ss(dt);
	else if (CI == 'o' || CI == 'u' || CI == 'O' || CI == 'U')
		i = for_ou(dt, CI == 'o' || CI == 'O' ? 8 : 10);
	else if (CI == 'x' || CI == 'X')
		i = for_xx(dt, CI);
	else if (CI == 'c' || CI == 'C')
		i = for_cc(dt);
	else if (CI == 'i' || CI == 'd' || CI == 'D')
		i = for_di(dt);
	else if (CI == 'p')
		i = for_xx(dt, 'x');
	else
		i = for_nimp(dt);
	return (i);
}
