/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 18:10:51 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/11 18:10:53 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] >= 'A' && str[index] <= 'Z')
			str[index] = str[index] - 'A' + 'a';
		index++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	index;

	index = 1;
	ft_strlowcase(str);
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 'a' + 'A';
	while (str[index] != '\0')
	{
		if ((str[index] >= ' ' && str[index] <= '/') ||
			(str[index] >= ':' && str[index] <= '@'))
			if (str[index + 1] >= 'a' && str[index + 1] <= 'z')
				str[index + 1] = str[index + 1] - 'a' + 'A';
		index++;
	}
	return (str);
}
