/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:08:00 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/17 01:32:38 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *d, const void *s, int c, size_t len)
{
	size_t				i;
	unsigned char		*tmp_dst;
	const unsigned char	*tmp_src;

	tmp_src = s;
	tmp_dst = d;
	i = 0;
	while (i < len)
	{
		tmp_dst[i] = tmp_src[i];
		if (tmp_src[i] == (unsigned char)c)
		{
			d = tmp_dst;
			return (d + i + 1);
		}
		i++;
	}
	d = tmp_dst;
	return (NULL);
}
