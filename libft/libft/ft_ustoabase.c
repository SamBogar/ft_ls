/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:57:07 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/18 14:21:36 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_ustoabs(unsigned short nbr, unsigned int bs, int up)
{
	char				*res;
	unsigned short		tmp_nbr;
	int					digs;

	res = 0;
	digs = 0;
	tmp_nbr = nbr;
	while ((tmp_nbr /= bs))
		digs++;
	while (!res)
		res = ft_memalloc(digs + 1);
	ft_bzero(res, digs + 1);
	res[0] = '-';
	while (digs >= 0)
	{
		tmp_nbr = (nbr % bs);
		if (tmp_nbr >= 10)
			res[digs] = (tmp_nbr - 10) + (up ? 'A' : 'a');
		else
			res[digs] = tmp_nbr + '0';
		nbr /= bs;
		digs--;
	}
	return (res);
}
