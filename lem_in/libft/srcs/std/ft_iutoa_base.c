/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iutoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 14:01:42 by llaporte          #+#    #+#             */
/*   Updated: 2017/05/13 19:17:52 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_iutoa_base(intmax_t value, int base)
{
	char		*result;
	void		*tofree;

	if (!value)
		return (ft_strdup("0"));
	if (!(result = ft_itoa_base(value, base)))
		return (0);
	if (ft_strchr(result, '-'))
	{
		tofree = result;
		result = ft_strerase(result, 0, 1);
		free(tofree);
	}
	return (result);
}
