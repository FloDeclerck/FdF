/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 12:51:53 by fdeclerc          #+#    #+#             */
/*   Updated: 2017/01/16 13:22:44 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mlx.h>

int			main(int ac, char **av)
{
	int		fd;
	t_map	map;

	fd = ft_read_file(ac, av);
	map = ft_read_map(fd);
	close(fd);
	return (0);
}
