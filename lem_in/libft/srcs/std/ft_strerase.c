/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strerase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 14:26:42 by llaporte          #+#    #+#             */
/*   Updated: 2017/05/11 18:51:49 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strerase(char const *s1, int where, int lenght)
{
	char	*result;
	int		i;
	int		j;
	int		k;

	if (!(result = ft_strnew(ft_strlen(s1) - lenght)))
		return (0);
	i = 0;
	j = 0;
	while (s1[j] && i != where)
		result[i++] = s1[j++];
	k = 0;
	while (s1[j] && k++ < lenght)
		++j;
	while (s1[j])
		result[i++] = s1[j++];
	return (result);
}
