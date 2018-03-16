/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:15:29 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/04 12:16:38 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int c)
{
	unsigned int		uc;

	uc = (unsigned int)c;
	if (uc < 'A' || uc > 'Z')
	{
		return (c);
	}
	return (c + 'a' - 'A');
}
