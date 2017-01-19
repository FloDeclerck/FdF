/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 16:05:31 by fdeclerc          #+#    #+#             */
/*   Updated: 2017/01/19 16:35:22 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

int		ft_pixel(t_coord *e, int x, int y)
{
	mlx_pixel_put(e->mlx, e->win, (x + e->move_x), (y + e->move_y), 0xFFFFFF);
	return (0);
}

int		ft_init_pixel(t_coord *e)
{
	int		i[2];

	i[0] = 0;
	while (i[0] != e->width)
	{
		i[1] = 0;
		while (i[1] != e->width)
		{
			ft_pixel(e, e->value[i[0]][i[1]][0],
					e->value[i[0]][i[1]][1]);
			i[1]++;
		}
		i[0]++;
	}
}

int		ft_init(int **value, int length, int width)
{
	t_coord e;

	e.move_x = 0;
	e.move_y = 0;
	e.zoom = 0;
	e.t_value = value;
	e.length = length;
	e.width = width;
	e.value = ft_init_coord(e.t_value, e.length, e.width, &e);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 2080, 1350, "fdf");
	mlx_expose_hook(e.win, &ft_expose_hook);
	e.indice = mlx_key_hook(e.win, &ft_key_hook, &e);
	e.indice = mlx_mouse_hook(e.win, &ft_mouse_hook, &e);
	e.indice = mlx_loop(e.mlx);
	return (0);
}

int		ft_error(int ac, char **av, char **str, int *rd)
{
	if (ac != 2)
	{
		ft_putstr("usage: ./fdf file\n");
		return (0);
	}
	if ((rd[0] = open(av[1], O_RDONLY)) == -1)
	{
		perror(av[1]);
		return (0);
	}
	if ((rd[1] = ft_open_file(rd[0], str)) == -1)
	{
		perror(av[1]);
		return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	char	*str;
	int		rd[2];
	int		length;
	int		width;
	int		**value;

	if (ft_error(ac, av, &str, rd) == 0)
		return (-1);
	if ((rd = ft_create_tab(&str, &length, &width)) == NULL)
	{
		ft_putstr(av[1]);
		ft_putstr(":Incorrect value in file\n");
		return (0);
	}
	ft_init(value, length, width);
	return (0);
}
