/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 21:32:18 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/22 14:54:02 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*if_zero(void)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * 2);
	if (!res)
		return (0);
	res[0] = '0';
	res[1] = 0;
	return (res);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		is_neg;
	int		digs;

	digs = ft_digitcounter(n);
	is_neg = 1;
	if (n == 0)
		return (if_zero());
	if (!(res = (char *)malloc(sizeof(char) * (digs + 2))))
		return (0);
	if (n < 0)
	{
		res[0] = '-';
		is_neg = -1;
		res[digs + 1] = 0;
	}
	else
		res[digs--] = 0;
	while (n > 0 || n < 0)
	{
		res[digs] = ((n % 10) * is_neg) + '0';
		n /= 10;
		digs--;
	}
	return (res);
}
