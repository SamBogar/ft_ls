/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 20:37:54 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/08 16:18:21 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t n)
{
	size_t			i;
	unsigned char	a;
	unsigned char	*tmp;

	a = (unsigned char)c;
	tmp = b;
	i = 0;
	while (i < n)
	{
		tmp[i] = a;
		i++;
	}
	b = tmp;
	return (b);
}
