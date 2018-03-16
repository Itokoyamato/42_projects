/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthuilli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 14:29:59 by dthuilli          #+#    #+#             */
/*   Updated: 2016/07/09 14:31:08 by dthuilli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_door(int *i, int *door_size, int offset_x, int door)
{
	int	o;

	o = door / 2;
	if ((offset_x == o) && (*door_size == (door / 2) - 1)
		&& (door > 3))
		ft_putchar('$');
	else
		ft_putchar('|');
	*i = *i + 1;
	*door_size = *door_size + 1;
}

int		print_line(int nbr, int offset_x, int door)
{
	int	i;
	int	z;
	int	door_size;

	door_size = -door / 2;
	z = 0;
	i = 0;
	while (i < offset_x)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putchar('/');
	i = 0;
	while (i <= nbr * 2)
	{
		while ((i == nbr + door_size) && (offset_x < door)
			&& (door_size <= door / 2))
			print_door(&i, &door_size, offset_x, door);
		ft_putchar('*');
		i = i + 1;
	}
	ft_putchar('\\');
	ft_putchar('\n');
	return (offset_x - 1);
}

void	print_content(int offset_x, int stage_size_x, int size, int size_door)
{
	int	i;
	int	stage_diff;
	int	ispair;

	i = 0;
	ispair = 4;
	stage_diff = 1;
	while (offset_x + 1)
	{
		if (i == size)
		{
			i += stage_size_x;
			offset_x -= stage_size_x;
			size = i + ispair;
			ispair++;
			if (stage_diff == 2)
			{
				stage_size_x++;
				stage_diff = 0;
			}
			stage_diff++;
		}
		offset_x = print_line(i, offset_x, size_door);
		i = i + 1;
	}
}

void	sastantua(int size)
{
	int	offset_x;
	int	stage_size_x;
	int	stage_size;
	int	i;
	int	o;

	i = 1;
	o = 0;
	stage_size_x = 2;
	stage_size = 3;
	if (size > 0)
	{
		while (i <= size)
		{
			offset_x = offset_x + 6 + o;
			if (i > 1)
				o++;
			if ((i > 1) && (i % 2))
				o++;
			i++;
		}
		if (!(size % 2))
			size = size - 1;
		print_content(offset_x - 4, stage_size_x, stage_size, size);
	}
}

int	main()
{
	sastantua(2);
	return (0);
}