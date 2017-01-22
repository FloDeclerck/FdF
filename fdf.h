/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 10:59:13 by fdeclerc          #+#    #+#             */
/*   Updated: 2017/01/22 15:40:14 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define LEN LENGTH

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft/libft.h"

typedef struct	s_coord
{
	int			***value;
	int			length;
	int			width;
	int			indice;
	void		*mlx;
	void		*win;
	int			x;
	int			y;
	int			max;
	int			move_x;
	int			move_y;
	int			move_xz;
	int			move_yz;
	int			zoom;
	int			**t_value;
	int			square_x;
	int			square_y;
}				t_coord;

int				ft_pixel(t_coord *e, int x, int y);
void			ft_init_pixel(t_coord *e);
int				ft_init(int **value, int length, int width);
int				ft_error(int ac, char **av, char **str, int *rd);
int				ft_open_file(int fd, char **file);
int				*ft_line_to_str(char *str, int *i);
int				**ft_new_tab(char **str, int *i, int *length);
void			ft_set_coord(int *x, int *begin, int n1, int n2);
void			ft_line_x(t_coord *e, int i, int j);
void			ft_line_y(t_coord *e, int i, int j);
void			ft_init_x(t_coord *e);
void			ft_init_y(t_coord *e);
void			ft_z_view(int *x, int *y, int *i, int **value);
void			ft_value_error(int **value, int length, int width);
int				***ft_coord_base(int **value, int len, int width, t_coord *e);
int				ft_init_expose(t_coord *e);
int				ft_arrow_key(int keycode, t_coord *e);
int				ft_arrow_key_end(int keycode, t_coord *e);
int				ft_mouse_key(int button, int x, int y, t_coord *e);

#endif
