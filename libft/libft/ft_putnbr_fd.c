/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 20:11:49 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/08 16:22:53 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_sup(int i, char *arr, int fd)
{
	if (i == 0)
		write(fd, "0", 1);
	i--;
	while (i >= 0)
	{
		write(fd, &arr[i], 1);
		i--;
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	int		bn;
	int		i;
	char	arr[20];

	bn = n;
	i = 0;
	if (n < 0)
		write(fd, "-", 1);
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
	ft_putnbr_sup(i, arr, fd);
}
