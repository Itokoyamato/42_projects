/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:46:11 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/07 16:56:01 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		splitcount(const char *s, char c)
{
	int		cnt;
	int		in_substring;

	in_substring = 0;
	cnt = 0;
	while (*s != '\0')
	{
		if (in_substring == 1 && *s == c)
			in_substring = 0;
		if (in_substring == 0 && *s != c)
		{
			in_substring = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static int		wlen(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**result;
	int		wordcount;
	int		index;

	if (!s)
		return (NULL);
	index = 0;
	wordcount = splitcount((const char *)s, c);
	result = (char **)malloc(sizeof(*result) * (wordcount + 1));
	if (result == NULL)
		return (NULL);
	while (wordcount--)
	{
		while (*s == c && *s != '\0')
			s++;
		result[index] = ft_strsub((const char *)s, 0, wlen((const char *)s, c));
		if (result[index] == NULL)
			return (NULL);
		s = s + wlen(s, c);
		index++;
	}
	result[index] = NULL;
	return (result);
}
