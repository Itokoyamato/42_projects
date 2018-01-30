/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 14:38:59 by llaporte          #+#    #+#             */
/*   Updated: 2017/05/11 10:27:09 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcharsize(wchar_t const wchar)
{
	if (wchar)
	{
		if (wchar <= 0x7F)
			return (1);
		else if (wchar <= 0x7FF)
			return (2);
		else if (wchar <= 0xFFFF)
			return (3);
		else if (wchar <= 0x10FFFF)
			return (4);
	}
	return (1);
}
