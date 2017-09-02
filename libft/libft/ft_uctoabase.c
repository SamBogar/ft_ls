/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uctoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:57:07 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/09 21:22:50 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_uctoabase(unsigned char nbr, int base, int is_upper)
{
	char			*res;
	unsigned char	tmp_int;
	int				digs;

	digs = 0;
	tmp_int = nbr;
	res = 0;
	while ((tmp_int /= base))
		digs++;
	while (!res)
		res = ft_memalloc(digs + 1);
	ft_bzero(res, digs + 1);
	res[0] = '-';
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
