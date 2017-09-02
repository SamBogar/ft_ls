/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printbits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 21:31:44 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/18 14:12:07 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_binary_digits(unsigned int n)
{
	int		i;

	i = 0;
	while (n)
	{
		n /= 2;
		i++;
	}
	return (i);
}

static char	*pop_res(char *res, unsigned int n)
{
	int		i;

	i = 0;
	while (n)
	{
		res[i] = n % 2 + '0';
		n /= 2;
		i++;
	}
	if (i % 8 != 0)
		while (i % 8 != 0)
		{
			res[i] = '0';
			i++;
		}
	res[i] = 0;
	res = ft_strrev(res);
	return (res);
}

void		ft_printbits(unsigned int n)
{
	char	*res;
	int		i;

	i = 0;
	if (n == 0)
		ft_putchar('0');
	res = (char *)malloc(sizeof(char) * (count_binary_digits(n) + 1));
	i = 1;
	res = pop_res(res, n);
	while (res[i - 1])
	{
		ft_putchar(res[i - 1]);
		if (i % 8 == 0)
			ft_putchar('\n');
		i++;
	}
}
