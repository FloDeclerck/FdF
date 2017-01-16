/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:09:32 by fdeclerc          #+#    #+#             */
/*   Updated: 2017/01/16 15:10:02 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

typedef struct  s_map
{
  size_t        map_width;
  size_t        map_height;
  size_t        point_xyz;
  t_2point      point2D;
  t_3point      point3D;
}               t_map;

typedef struct  s_2point
{
  int           x;
  int           y;
}               t_2point;

typedef struct  s_3point
{
  int           x;
  int           y;
  int           z;
}               t_3point;


#endif
