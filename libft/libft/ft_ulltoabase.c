/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoabase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:57:07 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/09 10:34:02 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_ulltoabase(unsigned long long nbr, int base, int is_upper)
{
	char		*res;
	long long	tmp_nbr;
	int			digs;

	res = 0;
	digs = 0;
	tmp_nbr = nbr;
	while ((tmp_nbr /= base))
		digs++;
	while (!res)
		res = ft_memalloc(digs + 1);
	ft_bzero(res, digs + 1);
	res[digs + 1] = 0;
	while (digs >= 0)
	{
		tmp_nbr = (nbr % base);
		if (tmp_nbr >= 10)
			res[digs] = (tmp_nbr - 10) + (is_upper ? 'A' : 'a');
		else
			res[digs] = tmp_nbr + '0';
		nbr /= base;
		digs--;
	}
	return (res);
}
