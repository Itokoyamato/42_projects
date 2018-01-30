/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:00:36 by dthuilli          #+#    #+#             */
/*   Updated: 2018/01/30 13:48:20 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t				len[2];
	size_t				i[2];
	char				*str;

	len[0] = (s1 == NULL ? 0 : ft_strlen(s1));
	len[1] = (s2 == NULL ? 0 : ft_strlen(s2));
	if ((str = malloc((len[0] + len[1] + 1) * sizeof(char))))
	{
		i[0] = 0;
		i[1] = 0;
		if (s1 != NULL)
			while (i[0] < len[0])
				str[i[1]++] = s1[i[0]++];
		i[0] = 0;
		if (s2 != NULL)
			while (i[0] < len[1])
				str[i[1]++] = s2[i[0]++];
		str[len[0] + len[1]] = '\0';
		return (str);
	}
	return (NULL);
}
