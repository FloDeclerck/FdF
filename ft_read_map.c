/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:44:07 by fdeclerc          #+#    #+#             */
/*   Updated: 2017/01/16 15:44:09 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

t_map   ft_read_map(int fd)
{
  t_list  *list;
  t_map   map;
  char    *line;

  ft_bzero(&map, sizeof(t_map));
  while (get_next_line(fd, &line))
  {
    
  }

}
