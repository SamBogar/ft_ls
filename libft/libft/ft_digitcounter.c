/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitcounter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 14:42:57 by sbogar            #+#    #+#             */
/*   Updated: 2017/05/23 19:41:49 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_digitcounter(int num)
{
	int	res;

	res = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		res++;
		num /= 10;
	}
	return (res);
}