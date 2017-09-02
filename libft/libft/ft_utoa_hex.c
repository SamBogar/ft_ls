/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 21:04:32 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/18 14:18:12 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_utoa_hex(unsigned int nbr, int is_upper)
{
	unsigned int	tmp;
	char			*res;
	int				alloc_size;

	tmp = nbr;
	alloc_size = 1;
	while ((tmp /= 16))
		alloc_size++;
	res = (char *)malloc(sizeof(char) * (alloc_size + 1));
	res[alloc_size] = 0;
	alloc_size--;
	while (alloc_size >= 0)
	{
		tmp = nbr % 16;
		if (tmp > 9)
			res[alloc_size] = tmp - 10 + (is_upper ? 'A' : 'a');
		else
			res[alloc_size] = tmp + '0';
		alloc_size--;
		nbr /= 16;
	}
	return (res);
}
