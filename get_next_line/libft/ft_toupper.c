/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:10:25 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/04 12:14:39 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_toupper(int c)
{
	unsigned int		uc;

	uc = (unsigned int)c;
	if (uc < 'a' || uc > 'z')
	{
		return (c);
	}
	return (c + 'A' - 'a');
}
