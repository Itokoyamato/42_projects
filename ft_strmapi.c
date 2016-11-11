/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:25:40 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/07 15:42:00 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (!s)
		return (NULL);
	if ((result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char))))
	{
		i = -1;
		while (s[++i])
			result[i] = f(i, s[i]);
		result[i] = '\0';
	}
	return (result);
}
