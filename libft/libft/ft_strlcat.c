/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 15:51:42 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/22 16:19:07 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	tmp;

	i = 0;
	dest_len = ft_strlen(dst);
	tmp = dest_len;
	while ((int)i < (int)size - (int)tmp - 1)
	{
		dst[dest_len] = src[i];
		i++;
		dest_len++;
	}
	dst[dest_len] = '\0';
	return (size >= tmp ? ft_strlen(src) + tmp : ft_strlen(src) + size);
}
