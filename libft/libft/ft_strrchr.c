/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 21:08:35 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/08 16:29:58 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*res;
	int		is_in;

	i = 0;
	is_in = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			res = (char*)s + i;
			is_in = 1;
		}
		i++;
	}
	if (!c)
	{
		res = (char*)s + i;
		return (res);
	}
	if (is_in == 1)
		return (res);
	return (NULL);
}
