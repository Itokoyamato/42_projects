/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 15:16:28 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/13 15:16:30 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && dest[i] != '\n')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\n';
	dest[i + 1] = '\0';
	return (dest);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		count;
	int		i;
	int		j;
	char	*str;

	i = 0;
	count = 0;
	while (count < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			count++;
			j++;
		}
		i++;
	}
	str = malloc(sizeof(str) * (count + 1));
	i = 0;
	while (i < argc - 1)
	{
		str = ft_strcat(str, argv[i + 1]);
		i++;
	}
	return (str);
}
