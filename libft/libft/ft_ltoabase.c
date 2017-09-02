/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:57:07 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/10 14:40:33 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ltoabase(long nbr, int base, int is_upper)
{
	char	*res;
	int		is_neg;
	long	tmp_int;
	int		digs;

	digs = nbr < 0 ? 1 : 0;
	is_neg = nbr < 0 ? -1 : 1;
	tmp_int = nbr;
	while ((tmp_int /= base))
		digs++;
	res = (char *)malloc(sizeof(char) * (digs + 1));
	ft_bzero(res, digs + 2);
	res[0] = '-';
	while (digs >= (is_neg == -1 ? 1 : 0))
	{
		tmp_int = (nbr % base) * is_neg;
		if (tmp_int >= 10)
			res[digs] = (tmp_int - 10) + (is_upper ? 'A' : 'a');
		else
			res[digs] = tmp_int + '0';
		nbr /= base;
		digs--;
	}
	return (res);
}
