/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:46:11 by fdeclerc          #+#    #+#             */
/*   Updated: 2016/11/09 16:29:56 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	index2;

	if (!*(little))
		return ((char *)big);
	index2 = 0;
	while (big[index2])
	{
		index = 0;
		while (big[index2 + index] == little[index] && index2 + index < len)
			if (!little[++index])
				return ((char *)(big + index2));
		index2++;
	}
	return (0);
}
