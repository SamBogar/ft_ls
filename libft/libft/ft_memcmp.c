/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:15:03 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/08 16:17:46 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	while (i < n)
	{
		str1 = (unsigned char*)s1;
		str2 = (unsigned char*)s2;
		s1++;
		s2++;
		i++;
		if (str1[0] != str2[0])
			return (str1[0] - str2[0]);
	}
	return (0);
}
