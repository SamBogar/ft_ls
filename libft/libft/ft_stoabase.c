/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:57:07 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/02 21:00:17 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_stoabase(short nbr, int base, int is_upper)
{
	char		*res;
	int			is_neg;
	short		tmp_nbr;
	int			digs;

	digs = nbr < 0 ? 1 : 0;
	is_neg = nbr < 0 ? -1 : 1;
	tmp_nbr = nbr;
	while ((tmp_nbr /= base))
		digs++;
	res = (char *)malloc(sizeof(char) * (digs + 1));
	ft_bzero(res, digs + 1);
	res[0] = '-';
	while (digs >= (is_neg == -1 ? 1 : 0))
	{
		tmp_nbr = (nbr % base) * is_neg;
		if (tmp_nbr >= 10)
			res[digs] = (tmp_nbr - 10) + (is_upper ? 'A' : 'a');
		else
			res[digs] = tmp_nbr + '0';
		nbr /= base;
		digs--;
	}
	return (res);
}
