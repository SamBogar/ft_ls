/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 22:07:26 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/08 16:16:29 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;
	t_list	*lst;

	if (!alst || !del)
		return ;
	lst = *alst;
	while (lst)
	{
		tmp = lst;
		ft_lstdelone(&lst, del);
		lst = tmp->next;
	}
	*alst = 0;
}
