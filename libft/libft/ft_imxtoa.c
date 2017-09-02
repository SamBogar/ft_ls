/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imxtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 20:09:57 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/18 14:11:35 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char			*ft_imxtoa(intmax_t n)
{
	uintmax_t	nbr;
	char		*res;
	int			digs;
	intmax_t	is_neg;

	digs = 0;
	nbr = n;
	is_neg = n < 0 ? -1 : 1;
	while ((nbr /= (intmax_t)10))
		digs++;
	res = (char*)malloc(sizeof(char) * (digs + 1));
	ft_bzero(res, digs + 1);
	if (n < 0)
	{
		res[0] = '-';
		digs++;
	}
	res[digs + 1] = 0;
	while (is_neg == -1 ? digs > 0 : digs >= 0)
	{
		res[digs] = ((n % 10) * is_neg) + '0';
		n /= 10;
		digs--;
	}
	return (res);
}
