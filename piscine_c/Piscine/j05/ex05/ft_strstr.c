/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 15:01:39 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/11 15:01:40 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		index;
	int		index2;
	int		character;

	index = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[index] != '\0')
	{
		index2 = index;
		character = 0;
		while (str[index2] == to_find[character])
		{
			index2++;
			character++;
			if (to_find[character] == '\0')
				return (&str[index]);
		}
		index++;
	}
	return (0);
}
