/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:48:48 by llaporte          #+#    #+#             */
/*   Updated: 2016/11/12 14:46:36 by llaporte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_of_word(char const *s, char c)
{
	int		t_len;
	int		i;

	i = 0;
	t_len = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			t_len++;
		while (s[i] != c && s[i])
			i++;
	}
	return (t_len);
}

static int	nb_of_char(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (!i)
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	result = (char **)malloc(sizeof(char *) * (nb_of_word(s, c) + 1));
	if (!result)
		return (0);
	while (s[j])
	{
		if (s[j] == c)
			j++;
		else
		{
			result[i] = ft_strsub(&(s[j]), 0, nb_of_char(&(s[j]), c));
			j = j + nb_of_char(&(s[j]), c);
			i++;
		}
	}
	result[i] = 0;
	return (result);
}
