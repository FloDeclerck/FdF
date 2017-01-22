/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:10:49 by fdeclerc          #+#    #+#             */
/*   Updated: 2017/01/22 15:41:24 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define BUFF_SIZE 4096

int				ft_open_file(int fd, char **file)
{
	ssize_t		bck;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;

	*file = (char *)malloc(sizeof(char) * 1);
	**file = '\0';
	while ((bck = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[bck] = '\0';
		tmp = ft_strjoin(*file, buff);
		free(*file);
		*file = tmp;
	}
	if (bck == -1)
		return (-1);
	return (0);
}

int				*ft_line_to_str(char *str, int *i)
{
	int		*line;
	char	**tab;

	tab = ft_strsplit(str, ' ');
	*i = 0;
	while (tab[*i])
		*i += 1;
	if (!(line = (int *)malloc(sizeof(line) * (*i + 1))))
		return (NULL);
	*i = 1;
	while (tab[*i])
	{
		line[*i] = ft_atoi(tab[*i]);
		*i += 1;
	}
	return (line);
}

int				**ft_new_tab(char **str, int *i, int *length)
{
	int			**tab;
	char		**tab_str;
	size_t		mod;

	if ((tab_str = ft_strsplit(*str, '\n')) == NULL)
		return (NULL);
	free(*str);
	*i = 0;
	mod = ft_strlen(tab_str[*i]);
	while (tab_str[*i])
		*i += 1;
	if (!(tab = (int **)malloc(sizeof(tab) * (*i + 1))))
		return (NULL);
	*i = 0;
	while (tab_str[*i])
	{
		if ((tab[*i] = ft_line_to_str(tab_str[*i], length)) == NULL)
			return (NULL);
		tab[*i] = ft_line_to_str(tab_str[*i], length);
		*i += 1;
	}
	return (tab);
}
