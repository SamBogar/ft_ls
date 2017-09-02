/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:05:00 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/08 20:42:28 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		ft_pwr(int n, int pwr)
{
	double	res;
	int		is_neg;

	is_neg = 1;
	if (pwr < 0)
	{
		is_neg = -1;
		pwr *= -1;
	}
	res = n;
	if (pwr == 0)
		return (1);
	while (pwr > 1)
	{
		res *= n;
		pwr--;
	}
	if (is_neg < 0)
		res = 1 / res;
	return (res);
}
