/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 19:45:43 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/16 21:20:08 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_sup(int i, char *arr)
{
	if (i == 0)
		write(1, "0", 1);
	i--;
	while (i >= 0)
	{
		write(1, &arr[i], 1);
		i--;
	}
}

void		ft_putnbr(int n)
{
	int		bn;
	int		i;
	char	arr[20];

	bn = n;
	i = 0;
	if (n < 0)
		write(1, "-", 1);
	while (bn != 0)
	{
		if (n >= 0)
		{
			arr[i] = (bn % 10) + '0';
			bn = (bn - (arr[i] - '0')) / 10;
			i++;
		}
		else
		{
			arr[i] = -(bn % 10) + '0';
			bn = (bn + (arr[i] - '0')) / 10;
			i++;
		}
	}
	ft_putnbr_sup(i, arr);
}
