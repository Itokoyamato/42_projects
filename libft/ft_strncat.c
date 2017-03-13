/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:28:46 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/09 13:48:38 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*result;

	result = s1;
	while (*s1)
		s1++;
	while (n-- && *s2)
		*s1++ = *s2++;
	*s1 = '\0';
	return (result);
}
