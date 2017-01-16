/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeclerc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:44:42 by fdeclerc          #+#    #+#             */
/*   Updated: 2017/01/16 15:44:46 by fdeclerc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H
#include <stdlib.h>

typedef struct  s_list
{
  void          *content;
  size_t        content_size;
  struct s_list *next;
}               t_list;

t_list          ft_lstnew(void const *content, size_t content_size);
t_list          *ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void            ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void            ft_lstadd(t_list **alst, t_list *new);
void            ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void            ft_lstdel(t_list **alst, void (*del)(void*, size_t));

#endif
