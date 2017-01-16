/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:14:02 by fdeclerc          #+#    #+#             */
/*   Updated: 2017/01/16 16:14:10 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"

static void get_coord(char **line)
{
    int coord;

    coord = ft_atoi(&line);
    while (ft_is_digit(**line))
    {
      ++(*line);
    }
    return (coord);
}

void  ft_parse_line(char *line, t_list **list)
{
  int x;
  int z;

  x = 0;
  set_coord(list, get_coord(&line));
  while (skip_space(&line))
  {
    set_coord(list, get_coord(&line));
  }
}
