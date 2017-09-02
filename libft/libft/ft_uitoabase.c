/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:27:08 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/18 14:25:24 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_resolve(unsigned int n, int base, int up, int size)
{
	unsigned int	tmp_int;
	char			*res;

	res = 0;
	while (!res)
		res = (char *)ft_memalloc(size + 1);
	ft_bzero(res, size + 1);
	size--;
	while (size >= 0)
	{
		tmp_int = n % base;
		if (tmp_int >= 10)
			res[size] = tmp_int - 10 + (up ? 'A' : 'a');
		else
			res[size] = n % base + '0';
		n /= base;
		size--;
	}
	return (res);
}

char				*ft_uitoabase(unsigned int n, int base, int up)
{
	unsigned int	nbr;
	int				size;

	nbr = n;
	size = 1;
	while ((nbr /= base))
		size++;
	return (ft_resolve(n, base, up, size));
}
