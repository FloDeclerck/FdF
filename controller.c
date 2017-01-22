/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:25:07 by fdeclerc          #+#    #+#             */
/*   Updated: 2017/01/22 15:39:21 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_init_expose(t_coord *e)
{
	ft_init_pixel(e);
	ft_init_x(e);
	ft_init_y(e);
	return (0);
}

int		ft_arrow_key(int keycode, t_coord *e)
{
	if (keycode == 126)
	{
		e->move_y = e->move_y - 30;
		mlx_clear_window(e->mlx, e->win);
		ft_init_expose(e);
	}
	if (keycode == 53)
		exit(0);
	return (0);
}

int		ft_arrow_key_end(int keycode, t_coord *e)
{
	int i;

	i = e->length;
	if (keycode == 123)
	{
		e->move_x = e->move_x - 30;
		mlx_clear_window(e->mlx, e->win);
		ft_init_expose(e);
	}
	if (keycode == 124)
	{
		e->move_x = e->move_x + 30;
		mlx_clear_window(e->mlx, e->win);
		ft_init_expose(e);
	}
	if (keycode == 125)
	{
		e->move_y = e->move_y + 30;
		mlx_clear_window(e->mlx, e->win);
		ft_init_expose(e);
	}
	ft_arrow_key(keycode, e);
	return (0);
}

int		ft_mouse_key(int button, int x, int y, t_coord *e)
{
	int i;

	i = e->length;
	x = y;
	if (button == 1)
	{
		e->zoom = e->zoom + 5;
		if (e->zoom == 100)
			e->zoom = 95;
		mlx_clear_window(e->mlx, e->win);
		e->value = ft_coord_base(e->t_value, e->length, e->width, e);
		ft_init_expose(e);
	}
	if (button == 2)
	{
		e->zoom -= 5;
		if (e->zoom == -35)
			e->zoom = -30;
		mlx_clear_window(e->mlx, e->win);
		e->value = ft_coord_base(e->t_value, e->length, e->width, e);
		ft_init_expose(e);
	}
	return (0);
}
