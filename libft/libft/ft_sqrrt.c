/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrrtdouble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 13:24:01 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/08 16:25:12 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static double	res_10(float i, double n)
{
	float		prev_num;
	float		t;

	prev_num = 0;
	t = 0;
	while (1)
	{
		if ((i + prev_num) * (i + prev_num) <= n && (i + t) * (i + t) >= n)
			break ;
		prev_num = t;
		t += 0.1;
	}
	i += prev_num;
	t = 0;
	prev_num = 0;
	while (1)
	{
		if ((i + prev_num) * (i + prev_num) <= n && (i + t) * (i + t) >= n)
			return (i + prev_num);
		prev_num = t;
		t += 0.01;
	}
	return (0);
}

double			ft_sqrrt(double n)
{
	float		i;
	float		t;
	float		prev_num;
	float		prev_t;

	prev_num = 0;
	prev_t = 0;
	i = 0;
	t = 0;
	while (1)
	{
		if (i * i >= n && prev_num * prev_num <= n)
			break ;
		prev_num = i;
		i++;
	}
	i = prev_num;
	prev_num = 0;
	return (res_10(i, n));
}
