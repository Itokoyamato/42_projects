/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 11:40:57 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/12 11:40:59 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int count;

	count = 0;
	if (argc < 1)
		return (0);
	while (argv[0][count] != '\0')
	{
		ft_putchar(argv[0][count]);
		count++;
	}
	ft_putchar('\n');
	return (0);
}
