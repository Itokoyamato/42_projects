/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:57:20 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/07 15:24:05 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*result;
	unsigned int	i;

	if (!s)
		return (NULL);
	if ((result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char))))
	{
		i = -1;
		while (s[++i])
			result[i] = f(s[i]);
		result[i] = '\0';
	}
	return (result);
}
