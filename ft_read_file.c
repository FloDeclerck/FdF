/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 14:52:11 by fdeclerc          #+#    #+#             */
/*   Updated: 2017/01/16 14:52:13 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_read_file(int ac, char **av)
{
  int fd;

  if (ac != 2)
  {
    ft_putstr("Usage :");
    ft_putstr(av[0]);
    ft_putendl("<filename>");
    exit(0);
  }
  if ((fd = open(av[1], O_RDONLY) == -1)
  {
    perror("Error");
    exit(0);
  }
  return (fd);
}
