/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 22:49:15 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/20 21:24:42 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	int		i;
	int		is_neg;
	long	number;

	i = 0;
	is_neg = 0;
	number = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	is_neg = str[i] == '-' ? 1 : 0;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		if (number >= 922337203685477580 && is_neg == 0)
			return (-1);
		else if (number >= 922337203685477580 && is_neg == 1)
			return (0);
		else
			number *= 10;
		number += (str[i] - 48);
		i++;
	}
	return (is_neg ? (int)-number : (int)number);
}
