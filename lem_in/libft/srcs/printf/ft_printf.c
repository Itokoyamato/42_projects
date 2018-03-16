/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:49:20 by llaporte          #+#    #+#             */
/*   Updated: 2017/05/18 15:26:08 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	next_arg(t_dataprintf *dt, int unsign)
{
	if ((LM == 'l' || CI == 'U' || CI == 'O' || CI == 'D' || CI == 'p')
		&& unsign)
		return ((unsigned long)va_arg(dt->arguments, unsigned long));
	else if (LM == 'L' && unsign)
		return ((unsigned long long)va_arg(dt->arguments, unsigned long long));
	else if (LM == 'j' && unsign)
		return ((uintmax_t)va_arg(dt->arguments, uintmax_t));
	else if (LM == 'z' && unsign)
		return (va_arg(dt->arguments, size_t));
	else if (unsign)
		return (va_arg(dt->arguments, unsigned int));
	else if ((LM == 'l' || CI == 'U' || CI == 'O' || CI == 'D' || CI == 'p'))
		return (va_arg(dt->arguments, long));
	else if (LM == 'L')
		return (va_arg(dt->arguments, long long));
	else if (LM == 'j')
		return (va_arg(dt->arguments, intmax_t));
	else if (LM == 'z')
		return (va_arg(dt->arguments, ssize_t));
	else
		return (va_arg(dt->arguments, int));
}

char		*iutoa_base_lm(t_dataprintf *dt, intmax_t arg, int base)
{
	if (LM == 'h' && CI != 'U' && CI != 'O' && CI != 'D')
	{
		return (ft_iutoa_base((short)arg, base));
	}
	else if (LM == 'H' && CI != 'U' && CI != 'O' && CI != 'D')
	{
		return (ft_iutoa_base((char)arg, base));
	}
	else
		return (ft_iutoa_base(arg, base));
}

char		*uitoa_base_lm(t_dataprintf *dt, intmax_t arg, int base)
{
	if (LM == 'h' && CI != 'U' && CI != 'O' && CI != 'D')
		return (ft_uitoa_base((unsigned short)arg, base));
	else if (LM == 'H' && CI != 'U' && CI != 'O' && CI != 'D')
		return (ft_uitoa_base((unsigned char)arg, base));
	else
		return (ft_uitoa_base(arg, base));
}

int			printf_manipulation(t_dataprintf *dt)
{
	while (dt->str[dt->i])
		if (dt->str[dt->i] == '%')
		{
			if (!(printf_conversion(dt)))
				return (0);
			++dt->cur_pcs;
			dt->i += CI ? 2 : 1;
		}
		else
			adc(dt, 1, 1, dt->str[dt->i]);
	return (1);
}

int			ft_printf(const char *restrict format, ...)
{
	t_dataprintf	*dt;

	if (!(dt = ft_memalloc(sizeof(t_dataprintf))))
		return (-1);
	if (!(dt->str = ft_strdup((char *)format)))
		return (-1);
	dt->i = 0;
	dt->count = 0;
	dt->cur_pcs = 0;
	if (!(prepare_parse(dt)))
		return (-1);
	if (!(parse_flags(dt)))
		return (-1);
	if (!(parse_precisions(dt)))
		return (-1);
	if (!(parse_minlenght(dt)))
		return (-1);
	if (!(parse_lengthmod(dt)))
		return (-1);
	va_start(dt->arguments, format);
	if (!(printf_manipulation(dt)))
		return (-1);
	va_end(dt->arguments);
	printf_cleaner(dt);
	return (dt->count);
}
