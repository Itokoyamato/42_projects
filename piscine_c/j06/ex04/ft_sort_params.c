/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 12:02:29 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/12 12:02:31 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
	{
		ft_putchar(str[count]);
		count++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int		index;

	index = 0;
	if (s1[0] != '\0' || s2[0] != '\0')
	{
		while (s1[index] == s2[index])
		{
			if (s1[index] == '\0' && s2[index] == '\0')
				return (0);
			index++;
		}
	}
	return (s1[index] - s2[index]);
}

void	ft_print_array(int argc, char **argv)
{
	int		index;

	index = 0;
	while (++index < argc)
	{
		ft_putstr(argv[index]);
		ft_putchar('\n');
	}
}

int		main(int argc, char **argv)
{
	char	*tmp;
	int		done;
	int		index;

	done = 1;
	while (done)
	{
		done = 0;
		index = 0;
		while (++index < argc - 1)
		{
			if (ft_strcmp(argv[index], argv[index + 1]) > 0)
			{
				tmp = argv[index];
				argv[index] = argv[index + 1];
				argv[index + 1] = tmp;
				done = 1;
			}
		}
	}
	ft_print_array(argc, argv);
	return (0);
}
