/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sttoabase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:57:07 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/18 14:24:25 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

char			*ft_sttoabase(size_t nbr, int base, int is_upper)
{
	char		*res;
	size_t		tmp_nbr;
	int			digs;

	res = 0;
	digs = 0;
	tmp_nbr = nbr;
	while ((tmp_nbr /= base))
		digs++;
	if (nbr == (size_t)LLONG_MIN)
		res[digs++] = '-';
	res = (char *)ft_memalloc(digs + 1);
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
