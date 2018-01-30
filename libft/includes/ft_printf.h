/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:48:16 by llaporte          #+#    #+#             */
/*   Updated: 2017/05/18 15:41:02 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "libft.h"

typedef struct		s_dataprintf
{
	int			i;
	int			nbcv;
	int			count;
	int			cur_pcs;
	va_list		arguments;
	char		*str;
	int			n;

	char		*length_mod;
	int			*precisions;
	int			*minimum_lenght;
	int			*flag_hash;
	int			*flag_zero;
	int			*flag_minu;
	int			*flag_plus;
	int			*flag_spac;
}					t_dataprintf;

int					ft_printf(const char *restrict format, ...);
void				ad(t_dataprintf *dt, int toaddi, char *towrite);
void				adc(t_dataprintf *dt, int toaddc, int toaddi, char towrite);
void				printf_cleaner(t_dataprintf *dt);
void				printf_putlm(t_dataprintf *dt);
void				printf_set_flags(t_dataprintf *dt, int i, int j);
int					printf_conversion(t_dataprintf *dt);
intmax_t			next_arg(t_dataprintf *dt, int unsign);
char				*iutoa_base_lm(t_dataprintf *dt, intmax_t arg, int base);
char				*uitoa_base_lm(t_dataprintf *dt, intmax_t arg, int base);
int					printf_manipulation(t_dataprintf *dt);
int					rekt_percents(t_dataprintf *dt);
size_t				ft_wstrlenp(wchar_t const *str, int pcs);

int					prepare_parse(t_dataprintf *dt);
int					parse_flags(t_dataprintf *dt);
int					parse_precisions(t_dataprintf *dt);
int					parse_minlenght(t_dataprintf *dt);
int					parse_lengthmod(t_dataprintf *dt);

int					for_nimp(t_dataprintf *dt);
int					for_ss(t_dataprintf *dt);
int					for_sl(t_dataprintf *dt);
int					for_cc(t_dataprintf *dt);
int					for_di(t_dataprintf *dt);
int					for_ou(t_dataprintf *dt, int base);
int					for_xx(t_dataprintf *dt, char x);

#endif
