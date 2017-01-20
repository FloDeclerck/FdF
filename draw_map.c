/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:36:47 by fdeclerc          #+#    #+#             */
/*   Updated: 2017/01/20 16:22:39 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_set_coord(int *x, int *begin, int n1, int n2)
{
	if (n1 < n2)
	{
		*x = n1;
		*begin = n2;
	}
	else
	{
		*x = n2;
		*begin = n1;
	}
}

void		ft_line_y(t_coord *e, int i, int j)
{
	float	m;
	float	p;
	int		begin;
	int		y;
	int		x;

	y = e->value[i + 1][j][1] - e->value[i][j][1];
	x = e->value[i + 1][j][0] - e->value[i][j][0];
	m = (float)y / (float)x;
	p = e->value[i][j][1] - (m * e->value[i][j][0]);
	ft_set_coord(&x, &begin, e->value[i][j][0], e->value[i + 1][j][0]);
	while (x < begin)
	{
		y = (int)((m * x + p) + 0.5);
		ft_pixel(e, x, y);
		x++;
	}
	ft_set_coord(&y, &begin, e->value[i][j][1], e->value[i + 1][j][1]);
	while (y < begin)
	{
		x = (int)((y - p) / m + 0.5);
		ft_pixel(e, x, y);
		y++;
	}
}

void		ft_line_x(t_coord *e, int i, int j)
{
	float	m;
	float	p;
	int		begin;
	int		x;
	int		y;

	y = e->value[i][j + 1][1] - e->value[i][j][1];
	x = e->value[i][j + 1][0] - e->value[i][j][0];
	m = (float)y / (float)x;
	p = e->value[i][j][1] - (m * e->value[i][j][0]);
	ft_set_coord(&x, &begin, e->value[i][j][0], e->value[i][j + 1][0]);
	while (x < begin)
	{
		y = (int)((m * x + p) + 0.5);
		ft_pixel(e, x, y);
		x++;
	}
	ft_set_coord(&y, &begin, e->value[i][j][1], e->value[i][j + 1][1]);
	while (y < begin)
	{
		x = (int)((y - p) / m + 0.5);
		ft_pixel(e, x, y);
		y++;
	}
}

void		ft_init_x(t_coord *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->length)
	{
		j = 0;
		while (j < e->width - 1)
		{
			ft_line_x(e, i, j);
			j++;
		}
		i++;
	}
}

void		ft_init_y(t_coord *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->length - 1)
	{
		j = 0;
		while (j < e->width)
		{
			ft_line_y(e, i, j);
			j++;
		}
		i++;
	}
}
