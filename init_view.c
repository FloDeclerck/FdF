/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:01:44 by fdeclerc          #+#    #+#             */
/*   Updated: 2017/01/22 15:41:10 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_z_view(int *x, int *y, int *i, int **value)
{
	float	tmp;

	tmp = 15. + (35. + i[2]) * (0.82 * i[0] + 0.57 * i[1]);
	*x = (int)(tmp + 0.5);
	tmp = 0.57 * (0.57 * i[0] - 0.82 * i[1]);
	tmp -= 0.06 * value[i[0]][i[1]];
	tmp *= (35. + i[2]);
	tmp += 533.;
	*y = (int)(tmp + 0.5);
}

void		ft_value_error(int **value, int length, int width)
{
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (i != length)
	{
		j = 0;
		while (j != width)
		{
			if (value[i][j] > 1000 || value[i][j] < -1000)
			{
				ft_putstr("Value of file is incorrect\n");
				exit(0);
			}
			j++;
		}
		i++;
	}
}

int			***ft_coord_base(int **value, int length, int width, t_coord *e)
{
	int		***coord;
	int		i[3];

	i[2] = e->zoom;
	if (!(coord = (int***)malloc(sizeof(coord) * (length + 1))))
		return (NULL);
	i[0] = 0;
	ft_value_error(value, length, width);
	while (i[0] < length)
	{
		if (!(coord[i[0]] = (int**)malloc(sizeof(coord) * (width + 1))))
			return (NULL);
		i[1] = 0;
		while (i[1] != width)
		{
			if (!(coord[i[0]][i[1]] = malloc(sizeof(coord) * 2)))
				return (NULL);
			ft_z_view(&coord[i[0]][i[1]][0], &coord[i[0]][i[1]][1], i, value);
			i[1]++;
		}
		i[0]++;
	}
	return (coord);
}
