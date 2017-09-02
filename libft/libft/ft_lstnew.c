/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 21:35:00 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/21 19:05:56 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *res;

	res = (t_list *)malloc(sizeof(t_list));
	if (!res)
		return (0);
	if (!content)
	{
		res->content = 0;
		res->content_size = 0;
		res->next = 0;
		return (res);
	}
	res->content = (void *)malloc(sizeof(content_size));
	res->content = ft_memmove(res->content, content, content_size);
	res->content_size = content_size;
	res->next = 0;
	return (res);
}
