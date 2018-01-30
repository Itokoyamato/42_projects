/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 15:50:22 by llaporte          #+#    #+#             */
/*   Updated: 2017/03/27 14:59:07 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strinsert(char const *s1, char const *s2, int where)
{
	char	*result;
	int		i;
	int		j;
	int		k;

	if (!(result = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (0);
	i = 0;
	j = 0;
	while (s1[j] && i != where)
		result[i++] = s1[j++];
	k = 0;
	while (s2[k])
		result[i++] = s2[k++];
	while (s1[j])
		result[i++] = s1[j++];
	return (result);
}
