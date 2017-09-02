/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:20:03 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/07 17:48:44 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*if_zero(void)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * 2);
	res[0] = 0;
	res[1] = 0;
	if (!res)
		return (0);
	res[0] = '0';
	res[1] = 0;
	return (res);
}

static void	ft_findchar(int tmp_int, char tmp_char, char *res, int digs)
{
	while (tmp_int != 0)
	{
		tmp_char++;
		tmp_int--;
	}
	res[digs] = tmp_char;
}

static char	*ft_resolve(int n, int base, char *res, int digs)
{
	char	tmp_char;
	int		tmp_int;
	int		is_neg;

	is_neg = n < 0 ? -1 : 1;
	while (n != 0)
	{
		tmp_char = 'A';
		tmp_int = (n % base) * is_neg;
		if (tmp_int >= 10)
		{
			tmp_int -= 10;
			ft_findchar(tmp_int, tmp_char, res, digs);
		}
		else
			res[digs] = tmp_int + '0';
		n /= base;
		digs--;
	}
	return (res);
}

char		*ft_itoabase(int n, int base)
{
	char	*res;
	int		is_neg;
	int		nbr;
	int		digs;

	nbr = n;
	digs = 0;
	is_neg = 1;
	if (n == 0)
		return (if_zero());
	while (nbr != 0)
	{
		nbr /= base;
		digs++;
	}
	res = (char *)malloc(sizeof(char) * (digs + 2));
	ft_bzero(res, digs + 2);
	if (n < 0)
	{
		res[0] = '-';
		is_neg = -1;
	}
	else
		digs--;
	return (ft_resolve(n, base, res, digs));
}
