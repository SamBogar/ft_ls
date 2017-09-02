/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:05:09 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/14 15:55:25 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*tmp_dst;
	const unsigned char	*tmp_src;

	tmp_src = (const unsigned char*)src;
	tmp_dst = (unsigned char*)dst;
	i = 0;
	while (i < len)
	{
		tmp_dst[i] = tmp_src[i];
		i++;
	}
	dst = tmp_dst;
	return (dst);
}
