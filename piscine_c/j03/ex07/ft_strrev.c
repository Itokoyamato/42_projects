/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 15:38:32 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/07 15:38:36 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	char	tmp;
	int		count;
	int		count2;

	count = 0;
	count2 = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	count--;
	while (count2 < count)
	{
		tmp = str[count];
		str[count] = str[count2];
		str[count2] = tmp;
		count--;
		count2++;
	}
	return (str);
}
