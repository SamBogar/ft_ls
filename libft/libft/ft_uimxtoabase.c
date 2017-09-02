/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uimxtoabase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:57:07 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/10 14:37:15 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_uimxtoabase(uintmax_t nbr, uintmax_t base, int is_upper)
{
	char		*res;
	uintmax_t	tmp_nbr;
	int			digs;

	res = 0;
	digs = 1;
	tmp_nbr = nbr;
	while ((tmp_nbr /= base))
		digs++;
	while (!res)
		res = (char *)ft_memalloc(digs + 1);
	ft_bzero(res, digs + 2);
	digs--;
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
