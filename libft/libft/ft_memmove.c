/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 17:52:20 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/20 18:03:23 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*tmp_dst;
	const unsigned char	*tmp_src;
	int					i;

	i = 0;
	tmp_dst = (unsigned char*)dst;
	tmp_src = (const unsigned char*)src;
	if ((const unsigned char*)tmp_dst > tmp_src)
	{
		if (len == 0)
			return (dst);
		len--;
		while (len + 1 != 0)
		{
			tmp_dst[len] = tmp_src[len];
			len--;
		}
	}
	else
		while (i < (int)len)
		{
			tmp_dst[i] = tmp_src[i];
			i++;
		}
	return (dst);
}
