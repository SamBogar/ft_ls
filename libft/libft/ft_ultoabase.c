/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:57:07 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/10 14:26:51 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ultoabase(unsigned long nbr, int base, int is_upper)
{
	char	*res;
	long	tmp_int;
	int		digs;

	res = 0;
	digs = 0;
	tmp_int = nbr;
	while ((tmp_int /= base))
		digs++;
	while (!res)
		res = (char *)ft_memalloc(digs + 1);
	ft_bzero(res, digs + 2);
	while (digs >= 0)
	{
		tmp_int = (nbr % base);
		if (tmp_int >= 10)
			res[digs] = (tmp_int - 10) + (is_upper ? 'A' : 'a');
		else
			res[digs] = tmp_int + '0';
		nbr /= base;
		digs--;
	}
	return (res);
}
