/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:12:09 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/17 01:32:22 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *s, int c, size_t len)
{
	size_t				i;
	unsigned char		*tmp;

	tmp = (unsigned char*)s;
	i = 0;
	while (i < len)
	{
		if (tmp[i] == (unsigned char)c)
			return ((void*)(s + i));
		i++;
	}
	return (NULL);
}
