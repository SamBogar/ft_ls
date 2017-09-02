/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 22:15:11 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/16 21:45:50 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*res;
	t_list	*curr;

	if (!lst || !f)
		return (0);
	tmp = f(lst);
	if (!(res = ft_lstnew(tmp->content, tmp->content_size)))
		return (0);
	curr = res;
	while (lst->next)
	{
		lst = lst->next;
		tmp = f(lst);
		if (!(curr->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (0);
		curr = curr->next;
	}
	return (res);
}
