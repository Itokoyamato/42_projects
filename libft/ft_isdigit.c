/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:51:21 by dthuilli          #+#    #+#             */
/*   Updated: 2016/11/04 11:55:26 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isdigit(int c)
{
	unsigned int		uc;

	uc = (unsigned int)c;
	if (uc < 48 || uc > 57)
	{
		return (0);
	}
	return (1);
}
