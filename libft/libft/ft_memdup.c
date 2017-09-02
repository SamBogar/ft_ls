/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:05:09 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/21 11:26:44 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memdup(const void *src, size_t len)
{
	void				*res;

	res = malloc(len);
	ft_memcpy(res, src, len);
	return (res);
}
