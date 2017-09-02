/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:32:41 by sbogar            #+#    #+#             */
/*   Updated: 2017/03/12 14:02:20 by sbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*res;

	if (s && f)
	{
		res = (char*)malloc((sizeof(char) * (ft_strlen(s) + 1)));
		if (!res)
			return (0);
		i = 0;
		while (s[i])
		{
			res[i] = f(s[i]);
			i++;
		}
		res[i] = 0;
		return (res);
	}
	return (NULL);
}
