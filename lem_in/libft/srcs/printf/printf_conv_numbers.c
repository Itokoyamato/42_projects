/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv_numbers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:56:37 by llaporte          #+#    #+#             */
/*   Updated: 2017/05/18 17:44:24 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		for_di2(t_dataprintf *dt, intmax_t arg, int l, int ispcs)
{
	int i;

	i = PCS;
	while ((ML + 1 - PCS - l * ispcs - (FS || FP || dt->n)) > 0
		&& (FZ && ispcs) && !FM)
	{
		adc(dt, 1, 0, '0');
		ML--;
	}
	while ((PCS - l) > 0)
	{
		adc(dt, 1, 0, '0');
		PCS--;
	}
	if (!(PCS == 0 && !ispcs && arg == 0))
		ad(dt, 0, iutoa_base_lm(dt, arg, 10));
	while ((ML + 1 - (i < l && !ispcs && arg != 0 ? l : i) - l * ispcs -
		(FS || FP || dt->n)) > 0 && FM)
	{
		adc(dt, 1, 0, ' ');
		ML--;
	}
	return (1);
}

int		for_di(t_dataprintf *dt)
{
	intmax_t	arg;
	int			l;
	int			ispcs;

	arg = next_arg(dt, 0);
	if (CI == 'D')
		dt->n = (arg * !(LM == 'h' || LM == 'H') < 0 || (unsigned short)arg *
			(LM == 'h') < 0 || (unsigned char)arg * (LM == 'H') < 0) ? 1 : 0;
	else
		dt->n = (arg * !(LM == 'h' || LM == 'H') < 0 || (short)arg *
			(LM == 'h') < 0 || (char)arg * (LM == 'H') < 0) ? 1 : 0;
	l = ft_nbrlen(arg, 10) * !(LM == 'h' || LM == 'H')
		+ ft_nbrlen((short)arg, 10) * (LM == 'h')
		+ ft_nbrlen((char)arg, 10) * (LM == 'H');
	ispcs = PCS == -1 ? 1 : 0;
	PCS = PCS == -1 ? 0 : PCS;
	while ((ML-- - (PCS < l && !ispcs && arg != 0 ? l : PCS) - l * ispcs -
		(FS || FP || dt->n)) > 0 && !(FZ && ispcs) && !FM)
		adc(dt, 1, 0, ' ');
	if ((FS || FP) && !dt->n)
		adc(dt, 1, 0, FP ? '+' : ' ');
	else if (dt->n)
		adc(dt, 1, 0, '-');
	return (for_di2(dt, arg, l, ispcs));
}

int		for_ou(t_dataprintf *dt, int base)
{
	uintmax_t	arg;
	int			nbl;
	int			i;
	int			oldpcs;

	arg = next_arg(dt, 1);
	nbl = ft_unbrlen(arg, base) * !(LM == 'h' || LM == 'H') +
		ft_unbrlen((unsigned short)arg, base) * (LM == 'h') +
		ft_unbrlen((unsigned char)arg, base) * (LM == 'H');
	oldpcs = PCS;
	i = PCS > nbl ? PCS : nbl;
	while (ML-- - i - FH * (LM == 'l' || LM == 'L' || oldpcs == -1)
		+ (oldpcs == 0) > 0 && !FM)
		adc(dt, 1, 0, FZ ? '0' : ' ');
	if ((FH && arg != 0) || (FH && PCS != -1))
		adc(dt, 1, 0, '0');
	while (PCS-- - nbl - FH > 0)
		adc(dt, 1, 0, '0');
	if (!(oldpcs == 0 && arg == 0))
		ad(dt, 0, uitoa_base_lm(dt, arg, base));
	while (ML-- + 1 - i - FH * (LM == 'l' || LM == 'L' || oldpcs == -1)
		+ (oldpcs == 0) > 0 && FM)
		adc(dt, 1, 0, ' ');
	return (1);
}

int		for_xx2(t_dataprintf *dt, char x, uintmax_t arg, int nbl)
{
	int		i;

	i = PCS;
	while ((PCS-- - nbl) > 0 ||
		((ML-- + 1 - (FH || CI == 'p') * 2 - i) > 0 && !FM))
		adc(dt, 1, 0, '0');
	if ((!(i == 0)))
		ad(dt, 0, x == 'X' ? uitoa_base_lm(dt, arg, 16) :
			ft_strtolower(uitoa_base_lm(dt, arg, 16)));
	while ((ML-- + 2 - (FH || CI == 'p') * 2 - i) > 0 && FM)
		adc(dt, 1, 0, ' ');
	return (1);
}

int		for_xx(t_dataprintf *dt, char x)
{
	uintmax_t	arg;
	int			nbl;

	arg = next_arg(dt, 1);
	nbl = ft_unbrlen(arg, 16) * !(LM == 'h' || LM == 'H') +
		ft_unbrlen((unsigned short)arg, 16) * (LM == 'h') +
		ft_unbrlen((unsigned char)arg, 16) * (LM == 'H');
	PCS = PCS < nbl && PCS ? nbl : PCS;
	while ((ML-- - (FH || CI == 'p') * 2 - PCS) > 0 && !FM && !FZ)
		adc(dt, 1, 0, ' ');
	if ((FH && arg != 0) || CI == 'p')
	{
		adc(dt, 1, 0, '0');
		adc(dt, 1, 0, x);
	}
	return (for_xx2(dt, x, arg, nbl));
}
