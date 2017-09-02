/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:55:23 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/22 14:55:41 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*res;

	res = (char*)malloc(sizeof(char) * size + 1);
	if (!res)
		return (0);
	res[size + 1] = 0;
	while (size + 1 != 0)
	{
		res[size] = 0;
		size--;
	}
	return (res);
}
