/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:45:37 by sbogar            #+#    #+#             */
/*   Updated: 2017/06/18 14:11:51 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** unsigned int to array function
*/

#include "libft.h"

char				*ft_utoa(unsigned int nbr)
{
	unsigned int	tmp;
	int				alloc_size;
	char			*res;

	tmp = nbr;
	alloc_size = 0;
	while ((tmp /= 10))
		alloc_size++;
	alloc_size++;
	res = (char*)malloc(sizeof(char) * (alloc_size + 1));
	res[alloc_size] = 0;
	alloc_size--;
	while (alloc_size >= 0)
	{
		res[alloc_size] = (nbr % 10) + '0';
		nbr /= 10;
		alloc_size--;
	}
	return (res);
}
